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

    string nameSpec[]={"#mu^{+}","#pi^{+}","K^{+}", "p", "d", "t", "^{3}He", "^{4}He"};

    // kRed, kBlue, kGreen+1, kMagenta+2, kAzure+8, kPink+1, kYellow+1, kOrange-3
    int color[] = {632, 600, 417, 618, 868, 901, 401, 797};

    TFile *f = TFile::Open("AnalysisResults.root");

    TList *histos = (TList*)f->Get("output");

    TCanvas *c = new TCanvas();


    TH2F *h = (TH2F*)histos->FindObject("fBetaTOFvspt_pos");
    h->Draw();

    auto legend = new TLegend(0.1,0.7,0.48,0.9);

    for(Int_t iS=0;iS<8;iS++) {

      string str_title = "hBetaTOFVSpt_Exp_"+nameSpec[iS];
      const char *title = str_title.c_str();
      TProfile *prof = (TProfile*)histos->FindObject(title);
      prof->SetLineColor(color[iS]);
      prof->Draw("same L");

      legend->AddEntry(prof,nameSpec[iS].c_str(),"f");

    }
    legend->SetBorderSize(0);
    legend->Draw();



  }
