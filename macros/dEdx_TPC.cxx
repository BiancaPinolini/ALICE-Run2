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

void dEdx_TPC(){

    string nameSpec[]={"#pi^{+}","K^{+}", "p", "d", "t", "^{3}He", "^{4}He"};

    TFile *f = TFile::Open("AnalysisResults.root");

    TList *histos = (TList*)f->Get("output");

    TCanvas *c = new TCanvas();
    gStyle->SetOptStat(0);

    TH2F *h = (TH2F*)histos->FindObject("fdEdxVSp_neg");
    c->SetLogy();
    c->SetLogz();
    h->GetYaxis()->SetRangeUser(5,2000);
    h->GetXaxis()->SetRangeUser(0.1,4.5);
    h->GetXaxis()->SetTitleOffset(1.2);
    h->SetTitle("");
    h->Draw("colz");

    /*for(Int_t iS=0;iS<7;iS++) {
      string str_title = "hDeDxExp_"+nameSpec[iS];
      const char *title = str_title.c_str();
      TProfile *prof = (TProfile*)histos->FindObject(title);
      prof->SetLineWidth(2);
      prof->SetLineColor(kBlack);
      prof->Draw("l same");

    }*/



  }
