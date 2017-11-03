//
//  otimo.cpp
//  Projeto2-SO
//
//  Created by Pedro Figueirêdo on 03/11/2017.
//  Copyright © 2017 Pedro Figueirêdo. All rights reserved.
//

#include "../Headers/otimo.hpp"

Otimo::Otimo(const std::vector<unsigned>& seqAcesso, std::vector< std::pair<unsigned,unsigned> >& quadros):
AlgoritmoSubstituicaoPagina(seqAcesso,quadros){}

Otimo::~Otimo(){}

int Otimo::calculaFaltaDePaginas_(){
    unsigned nQuadrosOcupados = 0;
    unsigned nQuadros = (unsigned) quadros_.size();
    unsigned nFaltaDePaginas = 0, aux = 0;
    
    // Resetando quadros
    for (auto& quadro : quadros_)
        quadro = {-1,-1};
    
    for (std::vector<unsigned>::const_iterator it = seqAcesso_.begin(); it != seqAcesso_.end(); it++){
        
        // Decrementa a distância para a próxima ocorrência
        for (auto& quadro : quadros_)
            quadro.second--;
        
        // Calcula-se a posição da página atual em quadros_
        auto position = std::find_if(quadros_.begin(), quadros_.end(), [it](auto& quadro){return quadro.first == *it;});
        
        // Se não estiver presente (falta de página)
        if (position == quadros_.end()) {
            
            // Se quadros_ estiver cheio, substitui-se a página de maior distância
            if (nQuadrosOcupados == nQuadros)
                quadros_[(std::max_element(quadros_.begin(), quadros_.end(), [](auto& quadro1, auto& quadro2){return quadro1.second < quadro2.second;})) - quadros_.begin()] = {*it, getDistancia(it)};
            
            // Caso contrário, popula-se o próximo espaço livre de quadros_
            else{
                quadros_[aux++] = {*it, getDistancia(it)};
                if (aux == nQuadros) aux = 0;
                nQuadrosOcupados++;
            }
            nFaltaDePaginas++;
        }
        // Se estiver presente, atualiza distância para próxima ocorrência
        else
            position->second = getDistancia(it);
    }
    
    return nFaltaDePaginas;
}

int Otimo::getDistancia(const std::vector<unsigned>::const_iterator& itPagina){
    auto position = std::find(itPagina + 1, seqAcesso_.end(), *itPagina);
    return position == seqAcesso_.end() ? std::numeric_limits<unsigned>::max() : (int) (position - itPagina);
}
