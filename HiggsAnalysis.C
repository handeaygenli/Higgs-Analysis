#define HiggsAnalysis_cxx
#include "HiggsAnalysis.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

void HiggsAnalysis::Loop()
{
//   In a ROOT session, you can do:
//      root> .L HiggsAnalysis.C
//      root> HiggsAnalysis t
//      root> t.GetEntry(12); // Fill t data members with entry number 12
//      root> t.Show();       // Show values of entry 12
//      root> t.Show(16);     // Read and show values of entry 16
//      root> t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch

   if (fChain == 0) return;

   int rapMin = -5;
   int rapMax =  5;

   //Statistic and Fitting box
   gStyle->SetOptStat("KsiouRMen");
   gStyle->SetOptFit(11112);

   //output file
   TFile *output = new TFile("HiggsAnalysisResults.root","RECREATE");

   //histograms
   TH1F *h_eventnumber = new TH1F("h_eventnumber","Number of events",5,0,5);

   //Canvas 
   TCanvas *c1 = new TCanvas("a1","1200Higgs", 1200,800);
   TCanvas *c2 = new TCanvas("a2","1200Higgs", 1200,800);
   TCanvas *c3 = new TCanvas("a3","1200Higgs", 1200,800);

   c1->Divide(2,3);
   c1->Draw();
   c2->Divide(2,3);
   c2->Draw();
   c3->Divide(2,1);
   c3->Draw();

   //For Z Boson
   TH1F *histMassPairZ = new TH1F("histMassPairZ",";m_{Z}(GeV/c^{2});Entries",5./0.02,0.,150.);
   histMassPairZ->SetTitle("Mass Pair Z Histogram");
   TH1F *histPtZ = new TH1F("histPtZ","jet p_{T}(GeV/c)", 150,0.,1500.);
   histPtZ->SetTitle("p_{T} Z Histogram");
   TH1F *histRapidityZ = new TH1F("histRapidityZ",";y;Entries",100,rapMin,rapMax);
   histRapidityZ->SetTitle("Rapidity Z Histogram");
   TH1F *histEtaZ = new TH1F("histEtaZ",";#eta;Entries",100,rapMin,rapMax);
   histEtaZ->SetTitle("#eta Z Histogram");
   TH1F *histPhiZ = new TH1F("histPhiZ",";#phi;Entries",100,rapMin,rapMax);
   histPhiZ->SetTitle("#Phi Z Histogram");
   TH1F *histTotalZ = new TH1F("histTotalZ",";ToplamZ;Entries",100,0,5);
   histTotalZ->SetTitle("Toplam Z Histogram");

   //For Higgs
   TH1F *histMassPairH = new TH1F("histMassPairHiggs",";m_{H}(GeV/c^{2});Entries",5./0.02,0.,150.);
   histMassPairH->SetTitle("Mass Pair Higgs Histogram");
   TH1F *histPtH = new TH1F("histPtHiggs","jet p_{T}(GeV/c)", 150,0.,1500.);
   histPtH->SetTitle("p_{T} Higgs Histogram");
   TH1F *histRapidityH = new TH1F("histRapidityHiggs",";y;Entries",100,rapMin,rapMax);
   histRapidityH->SetTitle("Rapidity Higgs Histogram");
   TH1F *histEtaH = new TH1F("histEtaHiggs",";#eta;Entries",100,rapMin,rapMax);
   histEtaH->SetTitle("#eta Higgs Histogram");
   TH1F *histPhiH = new TH1F("histPhiHiggs",";#phi;Entries",100,rapMin,rapMax);
   histPhiH->SetTitle("#Phi Higgs Histogram");
   TH1F *histTotalH = new TH1F("histTotalHiggs",";ToplamW;Entries",100,0,5);
   histTotalH->SetTitle("Toplam Higgs Histogram");

   //For d
   TH1F *histMassPaird = new TH1F("histMassPaird",";m_{d}(GeV/c^{2});Entries",140.,0.,1500.);
   histMassPaird->SetTitle("Mass Pair d Jet Histogram");
   TH1F *histPtd = new TH1F("histPtd","jet p_{T}(GeV/c)", 150,0.,1500.);
   histPtd->SetTitle("p_{T} d Jet Histogram");
   TH1F *histRapidityd = new TH1F("histRapidityd",";y;Entries",100,rapMin,rapMax);
   histRapidityd->SetTitle("Rapidity d Histogram");
   TH1F *histEtad = new TH1F("histEtad",";#eta;Entries",100,rapMin,rapMax);
   histEtad->SetTitle("#eta d Histogram");
   TH1F *histPhid = new TH1F("histPhid",";#phi;Entries",100,rapMin,rapMax);
   histPhid->SetTitle("#Phi d Histogram");
   TH1F *histTotald = new TH1F("histTotald",";Toplamd;Entries",100,0,5);
   histTotald->SetTitle("Toplam d jet Histogram");

   //For D
   TH1F *histMassPairD = new TH1F("histMassPairD",";m_{D}(GeV/c^{2});Entries",140.,0.,1500.);
   histMassPairD->SetTitle("Mass Pair D Jet Histogram");
   TH1F *histPtD = new TH1F("histPtD","jet p_{T}(GeV/c)", 150,0.,1500.);
   histPtD->SetTitle("p_{T} D Jet Histogram");
   TH1F *histRapidityD = new TH1F("histRapidityD",";y;Entries",100,rapMin,rapMax);
   histRapidityD->SetTitle("Rapidity D Histogram");
   TH1F *histEtaD = new TH1F("histEtaD",";#eta;Entries",100,rapMin,rapMax);
   histEtaD->SetTitle("#eta D Histogram");
   TH1F *histPhiD = new TH1F("histPhiD",";#phi;Entries",100,rapMin,rapMax);
   histPhiD->SetTitle("#Phi D Histogram");
   TH1F *histTotalD = new TH1F("histTotalD",";ToplamD;Entries",100,0,5);
   histTotalD->SetTitle("Toplam D Jet Histogram");

   //get event number
   int eventnumber = 0; 

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
      //eventnumber=++;
      cout << "Olay Sayisi = " << eventnumber << endl;
      h_eventnumber->Fill(1);
      
      //Define Variables
      TLorentzVector Z;
      TLorentzVector d;
      TLorentzVector D;
      TLorentzVector H;
      TLorentzVector Mde1;
      TLorentzVector Mde2;

      // Declarations
      Z.SetPtEtaPhiM (Particle_PT[2], Particle_Eta[2], Particle_Phi[2], Particle_M[2]);
      d.SetPtEtaPhiM (Particle_PT[3], Particle_Eta[3], Particle_Phi[3], Particle_M[3]);
      D.SetPtEtaPhiM (Particle_PT[4], Particle_Eta[4], Particle_Phi[4], Particle_M[4]);
      H.SetPtEtaPhiM (Particle_PT[5], Particle_Eta[5], Particle_Phi[5], Particle_M[5]);

      // Mass Calculation for E6
      Mde1 = Z + d;
      Mde2 = H + D;


      //Filling Histograms

      // E6 d
      histMassPaird->Fill(Mde1.M());
      histPtd->Fill(Mde1.Pt());
      histRapidityd->Fill(Mde1.Rapidity());
      histEtad->Fill(Mde1.Eta());
      histPhid->Fill(Mde1.Phi());

      // E6 D
      histMassPairD->Fill(Mde2.M());
      histPtD->Fill(Mde2.Pt());
      histRapidityD->Fill(Mde2.Rapidity());
      histEtaD->Fill(Mde2.Eta());
      histPhiD->Fill(Mde2.Phi());

      //Z
      histMassPairZ->Fill(Z.M());
      histPtZ->Fill(Z.Pt());
      histRapidityZ->Fill(Z.Rapidity());
      histEtaZ->Fill(Z.Eta());
      histPhiZ->Fill(Z.Phi());

      //H
      histMassPairH->Fill(H.M());
      histPtH->Fill(H.Pt());
      histRapidityH->Fill(H.Rapidity());
      histEtaH->Fill(H.Eta());
      histPhiH->Fill(H.Phi());


      
  } // end main event loop
      
      output->cd();

      h_eventnumber->Write();
      histMassPaird->Write();
      histPtd->Write();
      histRapidityd->Write();
      histEtad->Write();
      histPhid->Write();

      h_eventnumber->Write();
      histMassPairD->Write();
      histPtD->Write();
      histRapidityD->Write();
      histEtaD->Write();
      histPhiD->Write();

      h_eventnumber->Write();
      histMassPairZ->Write();
      histPtZ->Write();
      histRapidityZ->Write();
      histEtaZ->Write();
      histPhiZ->Write();

      h_eventnumber->Write();
      histMassPairH->Write();
      histPtH->Write();
      histRapidityH->Write();
      histEtaH->Write();
      histPhiH->Write();


      //Canvas
      c1->cd(1); histPtZ->Draw();
      c1->cd(3); histEtaZ->Draw();
      c1->cd(5); histPhiZ->Draw();
      c1->cd(2); histPtH->Draw();
      c1->cd(4); histEtaH->Draw();
      c1->cd(6); histPhiH->Draw();
      c1->SaveAs("ZveHiggsDagilimlar.ps");

      c2->cd(1); histPtd->Draw();
      c2->cd(3); histEtad->Draw();
      c2->cd(5); histPhid->Draw();
      c2->cd(2); histPtD->Draw();
      c2->cd(4); histEtaD->Draw();
      c2->cd(6); histPhiD->Draw();
      c2->SaveAs("JetDagilimlarr.ps");

      c3->cd(2); histMassPairH->Draw();
      gPad->SetLogy();
      c3->cd(1); histMassPairZ->Draw();
      gPad->SetLogy();
      c3->SaveAs("MassDagilimlarr.ps");


      output->Close();
      cout << "Finished!!!" << endl;

}