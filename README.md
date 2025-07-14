# 🎯 Relatório Gráfico do Genesys-Simulator

## 📋 Visão Geral

Este projeto implementa um **sistema de relatórios gráficos** para o Genesys-Simulator, similar ao Arena, permitindo visualização dinâmica e interativa das estatísticas de simulação através de diferentes tipos de gráficos.

## ✨ Funcionalidades Implementadas

### 📊 Visualização em HTML dos resultados

### 📊 Tipos de Gráficos
- **Gráfico de Barras** - Comparação de valores entre diferentes estatísticas
- **Gráfico de Pizza** - Visualização de proporções e percentuais
- **Gráfico de Linha** - Análise de tendências temporais
- **Gráfico de Dispersão** - Identificação de correlações
- **Histograma** - Distribuição de frequências

### 🔧 Configurações Avançadas
- **Seleção de Métricas**: Média, Mínimo, Máximo, Desvio Padrão, Variância, etc.
- **Atualização Automática**: Timer configurável (1-60 segundos)
- **Intervalos de Confiança**: Exibição opcional de margens de erro
- **Tabela de Estatísticas**: Visualização detalhada dos dados

### 📤 Exportação e Impressão
- **Exportação PDF**: Relatórios de alta qualidade para apresentações
- **Impressão**: Suporte completo a impressão de relatórios

## 🚀 Como Usar

### 1. Compilação
```bash
cd source/applications/gui/qt/GenesysQtGUI
qmake GenesysQtGUI.pro
make
```

### 2. Execução
```bash
./GenesysQtGUI
```

### 3. Acesso ao Relatório Gráfico
1. Abra o Genesys-Simulator
2. Carregue um modelo
3. Execute a simulação
4. Acesse a aba **"Results"** → **"Plots"** e **"Results"** → **"Results"** 
5. Configure o tipo de gráfico e métrica desejada

## 📚 Documentação

- **[Documentação Completa](documentation/GraphicalReportManager_Documentation.md)** - Arquitetura, casos de uso e decisões técnicas
- **[Testes Unitários](source/tests/)**

## 🏗️ Arquitetura

### Componentes Principais
- **GraphicalReportManager**: Classe principal responsável pela geração de gráficos
- **ChartData**: Estrutura de dados para estatísticas
- **Integração MainWindow**: Interface integrada na aba de resultados

### Padrões Utilizados
- **Observer Pattern**: Sinais e slots do Qt
- **Factory Pattern**: Criação de diferentes tipos de gráfico
- **Singleton**: Referência única ao Simulator

## 🎯 Requisitos Atendidos

### ✅ RF001 - Geração de Gráficos
- [x] Gráfico de barras com dados de estatísticas
- [x] Gráfico de pizza mostrando proporções
- [x] Gráfico de linha para tendências temporais
- [x] Gráfico de dispersão para correlações
- [x] Histograma para distribuição de frequências

### ✅ RF002 - Coleta de Dados Estatísticos
- [x] Coleta de dados de StatisticsCollector
- [x] Coleta de dados de Counter
- [x] Cálculo de métricas estatísticas
- [x] Tratamento de dados vazios ou inválidos

### ✅ RF003 - Configuração de Gráficos
- [x] Seleção de tipo de gráfico
- [x] Seleção de métrica estatística
- [x] Atualização automática de gráficos
- [x] Configuração de intervalos de confiança

### ✅ RF004 - Exportação e Impressão
- [x] Exportação para PDF
- [x] Impressão de relatórios

## 🎬 Casos de Uso

### UC001 - Visualizar Relatório Gráfico
1. Usuário acessa aba "Results" → "Plots"
2. Sistema carrega dados estatísticos automaticamente
3. Sistema exibe gráfico padrão com a métrica
4. Usuário pode alterar tipo de gráfico e métrica
5. Sistema atualiza gráfico em tempo real

### UC002 - Configurar Atualização Automática
1. Usuário marca checkbox "Atualização Automática"
2. Usuário define intervalo de atualização
3. Sistema inicia timer de atualização
4. Sistema atualiza gráficos automaticamente

### UC003 - Exportar Relatório
1. Usuário clica em "Print"
2. Sistema exibe diálogo de seleção de arquivo
3. Usuário escolhe formato e local
4. Sistema gera arquivo de exportação

## 🔧 Desenvolvimento

### Pré-requisitos
- Qt 5.12 ou superior
- Qt Charts module
- Compilador C++14
- Genesys-Simulator

### Estrutura de Arquivos
```
source/applications/gui/qt/GenesysQtGUI/
├── GraphicalReportManager.h          # Header principal
├── GraphicalReportManager.cpp        # Implementação
└── mainwindow.cpp                    # Integração

documentation/
└── GraphicalReportManager_Documentation.md
```