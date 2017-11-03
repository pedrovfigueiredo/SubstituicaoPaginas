//
//  lru.cpp
//  Projeto2-SO
//
//  Created by Pedro Figueirêdo on 03/11/2017.
//  Copyright © 2017 Pedro Figueirêdo. All rights reserved.
//

#include "../Headers/lru.hpp"

LRU::LRU(const std::vector<unsigned>& seqAcesso, std::vector< std::pair<unsigned,unsigned> >& quadros):
AlgoritmoSubstituicaoPagina(seqAcesso,quadros){}

LRU::~LRU(){}

int LRU::calculaFaltaDePaginas_(){
    int nFaltaDePaginas = 0;
    unsigned max = std::numeric_limits<unsigned>::max();
    
    // Seta custo para máximo de unsigned e reseta quadros
    for(auto& quadro : quadros_)
        quadro = {-1, max};
    
    for (auto pagina : seqAcesso_){
        
        // Incrementa distância da última referência (não incrementa se já for max)
        for (auto& quadro : quadros_)
            if (quadro.second != max)
                quadro.second++;
        
        auto position = std::find_if(quadros_.begin(), quadros_.end(), [pagina](auto& quadro){return quadro.first == pagina;});
        if (position == quadros_.end()){
            quadros_[(std::max_element(quadros_.begin(), quadros_.end(), [](auto& quadro1, auto& quadro2){return quadro1.second < quadro2.second;})) - quadros_.begin()] = {pagina,0};
            nFaltaDePaginas++;
        }
        else
            position->second = 0;
    }
    
    return nFaltaDePaginas;
}
