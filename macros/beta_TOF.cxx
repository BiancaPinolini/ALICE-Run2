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

void beta_TOF(){

    string nameSpec[]={"#pi^{+}","K^{+}", "p", "d", "t", "^{3}He", "^{4}He"};

    TFile *f = TFile::Open("AnalysisResults.root");

    TList *histos = (TList*)f->Get("output");

    TCanvas *c = new TCanvas();
    c->SetLogz();
    gStyle->SetOptStat(0);

    TH2F *h = (TH2F*)histos->FindObject("fBetaTOFvspt_neg");
    h->SetTitle("");
    h->GetXaxis()->SetRangeUser(0.3,10);
    h->GetXaxis()->SetTitleOffset(1.2);
    h->Draw("colz");
/*
    for(Int_t iS=0;iS<7;iS++) {

      string str_title = "hBetaTOFVSpt_Exp_"+nameSpec[iS];
      const char *title = str_title.c_str();
      TProfile *prof = (TProfile*)histos->FindObject(title);
      prof->SetLineWidth(1);
      prof->SetLineColor(kBlack);
      prof->Draw("same h");

    }*/


  }
