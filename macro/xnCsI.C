using namespace DER;
using namespace MAD;
using namespace UNIC;

void xnCsI(double mass_x=1*MeV)
{
   CsI *crystal = new CsI;
   Detector *detector = new Detector(crystal);
   detector->Mass=300*kg;
   detector->Threshold=100*eV;

   DarkMatter *x = new DarkMatter(mass_x);

   CrossSection *xn = new CrossSection;

   xn->SetDarkMatter(x);
   xn->SetDetector(detector);

   int nbins=100;
   double maxE=100*keV;
   TH1D *hRate = new TH1D("hRate", ";visible Energy [keV];rate/(1 keV)/(1 kg)/(1 year)",nbins,0,maxE);

   double rate;
   for (int i=1; i<nbins; i++) {
      double visibleE = i*keV;
      double realE = crystal->GetRealE(visibleE);
      rate = xn->IntegrateOverVerlocityDistribution(realE);
      hRate->SetBinContent(i,rate);
   }

   hRate->Draw();
}
