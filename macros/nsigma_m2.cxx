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

void nsigma_m2(){

    TFile *f = TFile::Open("AnalysisResults.root");

    TList *histos = (TList*)f->Get("output");

    TCanvas *c = new TCanvas();
    gStyle->SetOptStat(0);
    c->SetLogz();

    // #bar{t}, ^{3}#bar{He}
    TH3F *h = (TH3F*)histos->FindObject("NsigmaTPC_M2_p_#bar{t}");
    // cut on m2
    h->GetXaxis()->SetRangeUser(0,10); //(0,10)
    // cut on nsigma
    h->GetYaxis()->SetRangeUser(-3,3); //(-50,50)
    // cut on pt
    h->GetZaxis()->SetRangeUser(0.3,3.5); //(0,10)

    TH2D* h_yz = (TH2D*)h->Project3D("xz");
    h_yz->SetTitle(" ");
    h_yz->GetXaxis()->SetTitle("p_{T}/|z| (GeV/c)");
    h_yz->Draw("colz");

    TLine *line = new TLine(0.3, 7.88, 3.5, 7.88);
    line->SetLineColor(kRed);
    line->SetLineWidth(2);
    line->SetLineStyle(9);
    line->Draw("same");

    TLine *line_V = new TLine(2, 0, 2, 10);
    line_V->SetLineColor(kBlack);
    line_V->SetLineWidth(2);
    line_V->SetLineStyle(9);
    line_V->Draw("same");

    TLine *line_o1 = new TLine(0.3, 7, 3.5, 7);
    line_o1->SetLineColor(kBlack);
    line_o1->SetLineWidth(2);
    line_o1->SetLineStyle(9);
    line_o1->Draw("same");


}
