//
//  fifo.cpp
//  Projeto2-SO
//
//  Created by Pedro Figueirêdo on 03/11/2017.
//  Copyright © 2017 Pedro Figueirêdo. All rights reserved.
//

#include "../Headers/fifo.hpp"

FIFO::FIFO(const std::vector<unsigned>& seqAcesso, std::vector< std::pair<unsigned,unsigned> >& quadros):
AlgoritmoSubstituicaoPagina(seqAcesso,quadros){}

FIFO::~FIFO(){}

int FIFO::calculaFaltaDePaginas_(){
    const unsigned nQuadros = (unsigned) quadros_.size();
    unsigned nFaltaDePaginas = 0, aux = 0;
    
    // Reseta Quadros
    for (auto& quadro : quadros_)
        quadro = {-1,-1};
    
    for (auto pagina : seqAcesso_)
        if (std::find_if(quadros_.begin(), quadros_.end(), [pagina](auto& quadro){return quadro.first == pagina;}) == quadros_.end()) {
            nFaltaDePaginas++;
            (quadros_[aux++]).first = pagina;
            if (aux == nQuadros) aux = 0;
        }
    
    
    return nFaltaDePaginas;
}
