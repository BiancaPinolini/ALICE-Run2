#include <iostream>
#include "TH1F.h"
#include "TH2D.h"
#include "TH3F.h"
#include "TList.h"
#include "TCanvas.h"
#include "TStyle.h"
#include "TFile.h"
#include "string.h"

using namespace std;

void proj_TOF(){

    string nameSpec[]={"#pi^{+}","K^{+}", "p", "d", "t", "^{3}He", "^{4}He", "#pi^{-}","K^{-}","#bar{p}","#bar{d}","#bar{t}","^{3}#bar{He}","^{4}#bar{He}"};

    //string titleSpec[] = {"electron", "muon", "pion", "kaon", "proton", "deuton", "triton", "He3", "He4", "positron", "anti_muon", "anti_pion", "anti_kaon", "anti_proton", "anti_triton", "anti_3He", "anti_4He"}

    TFile *f = TFile::Open("AnalysisResults.root");

    TList *histos = (TList*)f->Get("output");

    TCanvas *c;
    gStyle->SetTitleSize(0.08, "t");
    gStyle->SetOptStat(0);

    for(Int_t iS=0;iS<14;iS++) {
      c = new TCanvas();
      c->Divide(2,3);

      string str_title = "NsigmaTOF_"+nameSpec[iS];
      const char *title = str_title.c_str();

      c->cd(1);
      string cd1_str = "n#sigma_{TOF} vs. p_{T} of "+nameSpec[iS];
      const char *cd1_char = cd1_str.c_str();

      TH2F *h = (TH2F*)histos->FindObject(title);
      h->GetYaxis()->SetTitle("n#sigma_{TOF}");
      h->GetYaxis()->SetRangeUser(-10,10);
      h->SetTitle("");
      h->SetTitle(cd1_char);
      c->cd(1)->SetLogz();
      h->Draw("colz");

      TH1D *h_sig[5];

      int i = 0;
      int m_bin = 3;
      int M_bin = 4;

      while (i<5) {

        c->cd(i+2);

        string str_hist = "p_{T} in 0." + to_string(m_bin) + " - 0." + to_string(M_bin) + " of " + nameSpec[iS];
        const char *name_hist = str_hist.c_str();

        h_sig[i] = (TH1D*) h->ProjectionY(name_hist, m_bin, M_bin);
        h_sig[i]->SetTitle(name_hist);
        h_sig[i]->Draw();

        m_bin++;
        M_bin++;
        i++;
      }

      if (0) {
      string pwd = "/home/bpinolin/alice_nuclei/task/plots/Nsigma/TOF/";
      string can_tit = pwd+nameSpec[iS]+".pdf";
      const char *can_title = can_tit.c_str();
      c->SaveAs(can_title);
      }
    }

}
