# YOLO Object Detection Test Project

Questo progetto raccoglie alcune sperimentazioni realizzate con YOLO per il rilevamento automatico di oggetti tramite immagini e webcam.

Il lavoro è diviso in due filoni principali:

## 1. Rilevamento viso e mani da webcam

Questa parte del progetto utilizza un modello YOLO addestrato per riconoscere in tempo reale alcuni elementi del volto e delle mani tramite la fotocamera del PC.

### Classi rilevate

- Mano_Dx
- Mano_Sx
- Occhi
- Naso
- Barba

### Funzionalità

- acquisizione immagini da webcam;
- rilevamento live tramite webcam;
- conteggio degli oggetti rilevati;
- conteggio per singola classe.

### File principali

- `Count_class.py`: script per rilevamento live con conteggio per classe rilevata;
- `train.yaml`: configurazione del dataset;
- `training.py`: script utilizzato per addestrare il modello;
- `model/best.pt`: modello addestrato.

---

## 2. Rilevamento ramponi ruote trattori

Questa parte del progetto utilizza un modello YOLO addestrato per riconoscere i ramponi presenti sulle ruote dei trattori a partire da immagini statiche.

### Classe rilevata

- Rampone

### Funzionalità

- analisi di immagini in input;
- rilevamento automatico dei ramponi;
- calcolo del centro di ogni rampone rilevato;
- disegno di un punto rosso al centro del rampone;
- conteggio totale dei ramponi rilevati per immagine.

### File principali

- `Centro_Rampone.py`: script per analizzare le immagini e segnare il centro dei ramponi;
- `train_Ramp.yaml`: configurazione del dataset;
- `training.py`: script utilizzato per addestrare il modello;
- `best.pt`: modello migliore addestrato per il rilevamento dei ramponi.

### Metriche modello ramponi

Versione modello:

- Precision: 0.98334
- Recall: 0.98675
- mAP50: 0.99261
- mAP50-95: 0.85692

---

## Dataset

Per entrambi i filoni sono state utilizzate immagini annotate manualmente tramite label YOLO.

Le label sono servite per addestrare i modelli, indicando al sistema la posizione degli oggetti da riconoscere all’interno delle immagini.

Dopo il training, i modelli generati possono essere utilizzati su nuove immagini o in tempo reale senza necessità di label.

---

## Nota

Il progetto nasce come sperimentazione iniziale. Alcuni path presenti negli script possono essere assoluti o riferiti alla struttura originale della macchina di sviluppo e potrebbero dover essere aggiornati in caso di spostamento del progetto.