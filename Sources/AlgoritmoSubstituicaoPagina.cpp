//
//  AlgoritmoSubstituicaoPagina.cpp
//  Projeto2-SO
//
//  Created by Pedro Figueirêdo on 03/11/2017.
//  Copyright © 2017 Pedro Figueirêdo. All rights reserved.
//

#include "../Headers/AlgoritmoSubstituicaoPagina.hpp"

AlgoritmoSubstituicaoPagina::AlgoritmoSubstituicaoPagina(const std::vector<unsigned>& seqAcesso,  std::vector< std::pair<unsigned,unsigned> >& quadros):quadros_(quadros),seqAcesso_(seqAcesso){}

AlgoritmoSubstituicaoPagina::~AlgoritmoSubstituicaoPagina(){}
