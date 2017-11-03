//
//  otimo.hpp
//  Projeto2-SO
//
//  Created by Pedro Figueirêdo on 03/11/2017.
//  Copyright © 2017 Pedro Figueirêdo. All rights reserved.
//

#ifndef otimo_hpp
#define otimo_hpp

#include <limits>
#include "AlgoritmoSubstituicaoPagina.hpp"

class Otimo : public AlgoritmoSubstituicaoPagina{
public:
    Otimo(const std::vector<unsigned>& seqAcesso, std::vector< std::pair<unsigned,unsigned> >& quadros);
    ~Otimo();
    
    int calculaFaltaDePaginas_();
    int getDistancia(const std::vector<unsigned>::const_iterator& itPagina);
};

#endif /* otimo_hpp */
