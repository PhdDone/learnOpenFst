#include <fst/fstlib.h>
#include <fst/script/compose.h>
#include <fst/arcsort.h>

using namespace fst;

int main() {
  StdVectorFst fst;
  // Adds state 0 to the initially empty FST and make it the start state. 
  fst.AddState();   // 1st state will be state 0 (returned by AddState) 
  fst.SetStart(0);  // arg is state ID

  // Adds two arcs exiting state 0.
  // Arc constructor args: ilabel, olabel, weight, dest state ID. 
  fst.AddArc(0, StdArc(0, 1, 0.5, 1));  // 1st arg is src state ID 
  fst.AddArc(0, StdArc(2, 2, 1.5, 1)); 

  // Adds state 1 and its arc. 
  fst.AddState();
  fst.AddArc(1, StdArc(3, 3, 2.5, 2));

  // Adds state 2 and set its final weight. 
  fst.AddState();
  fst.SetFinal(2, 3.5);  // 1st arg is state ID, 2nd arg weight 
  fst.Write("binary.fst");

  StdVectorFst fst1;
  fst1.AddState();
  fst1.SetStart(0);

  fst1.AddArc(0, StdArc(1, 0, 0.1, 1));

  fst1.AddState();

  fst1.SetFinal(1, 0);
  fst1.Write("TT1.fst");

  StdVectorFst fst2;
  fst2.AddState();
  fst2.SetStart(0);

  fst2.AddArc(0, StdArc(0, 1, 0.2, 1));

  fst2.AddState();
  fst2.SetFinal(1, 0);
  fst2.Write("TT2.fst");

  /*
  StdFst *input = StdFst::Read("T1.fst");
  // Reads in the transduction model.
  StdFst *model = StdFst::Read("T3.fst");
  // The FSTs must be sorted along the dimensions they will be joined.
  // In fact, only one needs to be so sorted.
  // This could have instead been done for "model.fst" when it was created.
  //ArcSort(input, StdOLabelCompare());
  //ArcSort(model, StdILabelCompare());
  // Container for composition result.
  StdVectorFst result;
  // Create the composed FST
  Compose(*input, *model, &result);
  result.Write("result.fst");
  // Just keeps the output labels
  //Project(&result, PROJECT OUTPUT);
  */
  StdVectorFst result;
  Compose(fst1, fst2, &result);
  result.Write("result.fst");
  return 0;
}
