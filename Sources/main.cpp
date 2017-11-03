//
//  main.cpp
//  Projeto2-SO
//
//  Created by Pedro Figueirêdo on 03/11/2017.
//  Copyright © 2017 Pedro Figueirêdo. All rights reserved.
//

#include <iostream>
#include "../Headers/AlgoritmoSubstituicaoPagina.hpp"
#include "../Headers/fifo.hpp"
#include "../Headers/otimo.hpp"
#include "../Headers/lru.hpp"

void readFromFile(const std::string& filePath, std::vector<unsigned>& seqAcesso, std::vector< std::pair<unsigned,unsigned> >& quadros){
    std::ifstream file(filePath);
    
    if (file.is_open()) {
        int aux;
        file >> aux;
        quadros.resize(aux);
        
        while (file >> aux)
            seqAcesso.push_back(aux);
    }else
        std::cerr << "Não foi possível abrir o arquivo." << std::endl;
    
    file.close();
}

int main(int argc, const char * argv[]) {
    //const std::string filePath = "/Users/PedroFigueiredo/Google Drive/5 Período/Sistemas Operacionais I/Projetos/Projeto 2/Projeto2-SO/Projeto2-SO/Instances/instance3.txt";
    const std::string filePath = argv[1];
    
    std::vector< std::pair<unsigned,unsigned> > quadros;
    std::vector<unsigned> seqAcesso;
    
    readFromFile(filePath, seqAcesso, quadros);
    
    AlgoritmoSubstituicaoPagina * a1 = new FIFO(seqAcesso,quadros);
    AlgoritmoSubstituicaoPagina * a2 = new Otimo(seqAcesso,quadros);
    AlgoritmoSubstituicaoPagina * a3 = new LRU(seqAcesso,quadros);
    
    
    std::cout << "FIFO " << a1->calculaFaltaDePaginas_() << std::endl;
    std::cout << "OTM " << a2->calculaFaltaDePaginas_() << std::endl;
    std::cout << "LRU " << a3->calculaFaltaDePaginas_() << std::endl;
    
    return 0;
}
