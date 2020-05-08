#ifndef CES12_ALUNOINDEXPOINTS_H
#define CES12_ALUNOINDEXPOINTS_H

#include <vector>
#include <map>
#include <IndexPointsAbstract.h>

class IndexPointsAluno : public IndexPointsAbstract {
    
public:
    
    long size() ;
        
    void add (float key, long idx ) ;
    
    //look for a range of values
    void find(std::vector<long> &res, float first, float last ) ;
    
    
private: 
    // ALUNO DEVE IMPLEMENTAR ALGO COM O MESMO COMPORTAMENTO DE MULTIMAP
    std::multimap<float, long> _map;
    
};//class


#endif
