
#include <IndexPointsStlMultimap.h>


void IndexPointsStlMultimap::find(std::vector<long> &res, float first, float last ) {
    
    
  auto itlow = _map.lower_bound (first);  // itlow points to first
  auto itup = _map.upper_bound (last);   // itup points to next after last (not to last)
  // print range [itlow,itup), which is the same as [itlow, last] or [first, last]
  for (auto it=itlow; it!=itup; ++it)
    //std::cout << (*it).first << " => " << (*it).second << '\n';
    res.push_back((*it).second);

    
    
}//find
