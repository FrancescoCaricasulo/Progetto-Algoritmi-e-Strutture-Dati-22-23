# Esercizio 3-4
Cartella che contiene tutti i file che consentono il funzionamento dell'esercizio 4, ovvero l'esecuzione dell'algoritmo di Prim su un grafo.

# Disposizione in cartelle
La cartella corrente di questa repository contiene le seguenti cartelle:
- .idea: file dell'IDE usato (IntelliJ Idea)
- Main: contiene il sorgente che implemente l'algoritmo
- run: contiene tutti i sorgenti pronti per essere compilati
- README.md

# Nota
Nella consegna si è chiesto di passare il nome del file in args[1]. Per soddisfare questa richiesta si è trovata la seguente soluzione: java GraphFromFile qualsiasiParametro nomeFile.csv.
Il motivo è che probabilmente la versione del compilatore usato comincia a prendere i parametri da args[0].

# Scelte implementative
Si è scelto di implementare l'algoritmo di Prim attraverso l'uso di una coda di priorità implementata con uno heap minimo. Si è scelto uno heap minimo per la natura stessa dell'algoritmo di Prim: calcolare l'albero minimo ricoprente.
