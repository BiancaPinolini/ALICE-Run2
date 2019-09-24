#include <iostream>
#include "TH1F.h"
#include "TH2D.h"
#include "TH3F.h"
#include "TList.h"
#include "TCanvas.h"
#include "TStyle.h"
#include "TFile.h"
#include "string.h"
#include "TLine.h"

using namespace std;

void proj_m2(){

    TFile *f = TFile::Open("AnalysisResults.root");

    TList *histos = (TList*)f->Get("output");

    TCanvas *c = new TCanvas("c1");
    gStyle->SetOptStat(0);

    // #bar{t}, ^{3}#bar{He}
    TH3F *h = (TH3F*)histos->FindObject("NsigmaTPC_M2_p_^{3}#bar{He}");
    // cut on m2
    h->GetXaxis()->SetRangeUser(2,6); //(0,10)
    // cut on nsigma
    h->GetYaxis()->SetRangeUser(3,15); //(-50,50)
    // cut on pt
    h->GetZaxis()->SetRangeUser(0.3,5); //(0,10)

    // ******************************************************************Nsigma vs PT
    //c->Divide(2,1);
    //c->cd(1);
    /*c->SetLogz();

    TH2D* h_yz = (TH2D*)h->Project3D("yz");
    h_yz->SetTitle(" ");
    h_yz->GetYaxis()->SetTitle("n#sigma_{TPC}");
    h_yz->GetXaxis()->SetTitle("p_{T}/|z| (GeV/c)");
    h_yz->Draw("colz");*/

    // ******************************************************************M2
    // c->cd(2);
    TH2D* h_yx = (TH2D*)h->Project3D("yx");
    TH1D *h_sig = (TH1D*) h_yx->ProjectionX();


    h_sig->SetLineWidth(2);
    h_sig->SetTitle(" ");
    //h_sig->Fit("gaus");
    h_sig->Draw();

/*
    TLine *line = new TLine(5, -20, 5, 15);
    line->SetLineColor(kBlack);
    line->SetLineWidth(2);
    line->SetLineStyle(9);
    line->Draw("same");

    TLine *line_o1 = new TLine(0.3, -3, 7, -3);
    line_o1->SetLineColor(kBlack);
    line_o1->SetLineWidth(2);
    line_o1->SetLineStyle(9);
    line_o1->Draw("same");

    TLine *line_o2 = new TLine(0.3, 3, 7, 3);
    line_o2->SetLineColor(kBlack);
    line_o2->SetLineWidth(2);
    line_o2->SetLineStyle(9);
    line_o2->Draw("same");
    */

    //cout << "h_sig events: " << h_sig->Integral() << endl;

}
