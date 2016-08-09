#ifndef DER_DARKMATTER_H
#define DER_DARKMATTER_H

#include <TF1.h>

namespace DER { class DarkMatter; }

class DER::DarkMatter : public TObject
{
   protected:
      double Mass; 
      TF1 *fVerlocityDistribution;

   public:
      DarkMatter(double mass): TObject(), Mass(0), fVerlocityDistribution(0) {};
      virtual ~DarkMatter() { if (fVerlocityDistribution) delete fVerlocityDistribution; }

      double NumberDensity(double Vlower, double Vupper);

      ClassDef(DarkMatter,1);
};

#endif
