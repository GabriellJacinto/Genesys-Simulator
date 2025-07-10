#include <QtTest/QtTest>
#include "mainwindow.h"
#include <QtCharts/QChartView>
#include <QtCharts/QChart>

class TestResultsPlot : public QObject {
    Q_OBJECT
private slots:
    void initTestCase() {
        // Setup global test state if needed
    }

    void cleanupTestCase() {
        // Cleanup global test state if needed
    }

    void test_updateResultsPlot_updatesChart() {
        MainWindow w;
        w.updateResultsPlot();
        // Verifica se o chartView foi criado e tem um gráfico
        QVERIFY(w.getChartView() != nullptr);
        QChart* chart = w.getChartView()->chart();
        QVERIFY(chart != nullptr);
        // Verifica se o título do gráfico não está vazio (indicando atualização)
        QVERIFY(!chart->title().isEmpty());
        // Verifica se há pelo menos uma série de dados
        QVERIFY(chart->series().size() > 0);
    }
};

QTEST_MAIN(TestResultsPlot)
#include "test_resultsplot.moc" 