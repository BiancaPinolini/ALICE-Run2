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

void proj_TPC(){

    string nameSpec[]={"e^{+}","#mu^{+}","#pi^{+}","K^{+}", "p", "d", "t", "^{3}He", "^{4}He", "e^{-}","#mu^{-}","#pi^{-}","K^{-}","#bar{p}","#bar{d}","#bar{t}","^{3}#bar{He}","^{4}#bar{He}"};

    TFile *f = TFile::Open("AnalysisResults.root");

    TList *histos = (TList*)f->Get("output");

    TCanvas *c;

    for(Int_t iS=0;iS<18;iS++) {
      c = new TCanvas();
      c->Divide(2,3);

      string str_title = "NsigmaTPC_0_"+nameSpec[iS];
      const char *title = str_title.c_str();

      TH3F *h_sig_pt = (TH3F*)histos->FindObject(title);

      // 3D -> 2D
      c->cd(1);
      TH2D *h = (TH2D*) h_sig_pt->Project3D("zx");
      h->GetYaxis()->SetRangeUser(-10,10);
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

      if (1) {
      string pwd = "/home/bpinolin/alice_nuclei/task/plots/Nsigma/TPC/";
      string can_tit = pwd+nameSpec[iS]+".pdf";
      const char *can_title = can_tit.c_str();
      c->SaveAs(can_title);
      }
    }




}
