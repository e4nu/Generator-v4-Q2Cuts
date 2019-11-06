//____________________________________________________________________________
/*!

\class    genie::SecondNucleonEmissionI

\brief    Interface to drive the a second nucleon emission from a nucleus
          Specfic impelmentations will have different physics

\author   Afroditi Papadopoulou <apapadop \at mit.edu>
          Massachusetts Institute of Technology - October 04, 2019
          Marco Roda <mroda \at liverpool.ac.uk>
          University of Liverpool

\created  October 04, 2019

\cpright  Copyright (c) 2003-2019, The GENIE Collaboration
          For the full text of the license visit http://copyright.genie-mc.org
          or see $GENIE/LICENSE
*/
//____________________________________________________________________________

#ifndef _SECOND_NUCLEON_EMISSION_H_
#define _SECOND_NUCLEON_EMISSION_H_

#include "Framework/EventGen/EventRecordVisitorI.h"
#include "Framework/GHEP/GHepParticle.h"
#include "Framework/Interaction/Target.h"

namespace genie {

class NuclearModelI;

class SecondNucleonEmissionI : public EventRecordVisitorI {

public :

  virtual ~SecondNucleonEmissionI();

  //-- overload the Algorithm::Configure() methods to load private data
  //   members from configuration options
  void Configure(const Registry & config);
  void Configure(string config);

protected:

  virtual bool EmitSecondNucleon( GHepRecord * evrec, const int eject_nucleon_pdg ) const ;

  const NuclearModelI *  fNuclModel;   ///< nuclear model

  SecondNucleonEmissionI();
  SecondNucleonEmissionI(string config);

  void LoadConfig (void);

private:

};

}      // genie namespace
#endif // _SRC_NUCLEAR_RECOIL_H_
