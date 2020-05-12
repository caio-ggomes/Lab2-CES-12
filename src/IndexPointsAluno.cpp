
#include "IndexPointsAluno.h"

/// returns the number of elements in the index
long IndexPointsAluno::size() { return redblack.get_counter();}

/// adds new element to the index. 
void IndexPointsAluno::add (float key, long idx ) {
  redblack.insert_node(key, idx);}


void IndexPointsAluno::find(std::vector<long> &res, float first, float last ) {
    
    
  // it is float, so it is not possible to compare with ==
  // the only thing that makes sense is too look for a range from
  // a min value to a max value. 
  // stl::multimap implements this using iterators 
  // you do not need to use iterators, but you need to fill the answer in O(k + logn)
  // where k is the number of elements in the range from first to last
  // in other words: NAO VALE FAZER INORDER COMPLETO E SELECIONAR O RANGE
  // PRECISA UM INORDER ESPERTO QUE ACHA O FIRST em O(log n) E CONTINUA ATE O LAST
  redblack.find(redblack.get_root(), res, first, last);
}//find
