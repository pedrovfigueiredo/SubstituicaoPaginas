//
//  fifo.hpp
//  Projeto2-SO
//
//  Created by Pedro Figueirêdo on 03/11/2017.
//  Copyright © 2017 Pedro Figueirêdo. All rights reserved.
//

#ifndef fifo_hpp
#define fifo_hpp

#include "AlgoritmoSubstituicaoPagina.hpp"

class FIFO : public AlgoritmoSubstituicaoPagina{
public:
    FIFO(const std::vector<unsigned>& seqAcesso, std::vector< std::pair<unsigned,unsigned> >& quadros);
    ~FIFO();
    
    int calculaFaltaDePaginas_();
};

#endif /* fifo_hpp */
