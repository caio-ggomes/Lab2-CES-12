#ifndef CES12_INDEXPOINTSABS_H
#define CES12_INDEXPOINTSABS_H

#include <vector>


class IndexPointsAbstract {
    
public:
    
    IndexPointsAbstract() : _tolerance(1e-3) { }
    
    virtual long size() = 0;
    
    virtual void add (float key, long idx ) =0 ;
    
    //look for a range of values
    virtual void find(std::vector<long> &res, float first, float last ) = 0;
    
    // convenience function to find a single value
    void find(std::vector<long> &res, float value ) {
        
        find(res, value - _tolerance, value + _tolerance );
    }
    
    
    void setTolerance( float newtol ) { _tolerance = newtol; }
    float getTolerance() { return _tolerance; } 
    
private: 
    float _tolerance;
    
};//class


#endif
