//
//  lru.hpp
//  Projeto2-SO
//
//  Created by Pedro Figueirêdo on 03/11/2017.
//  Copyright © 2017 Pedro Figueirêdo. All rights reserved.
//

#ifndef lru_hpp
#define lru_hpp

#include <stack>
#include "AlgoritmoSubstituicaoPagina.hpp"

class LRU : public AlgoritmoSubstituicaoPagina{
public:
    LRU(const std::vector<unsigned>& seqAcesso, std::vector< std::pair<unsigned,unsigned> >& quadros);
    ~LRU();
    
    int calculaFaltaDePaginas_();
};

#endif /* lru_hpp */
