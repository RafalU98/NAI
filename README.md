# NAI
Czwiczenia z NAI PJATK-Gdańsk 2020

Tutaj bedą się znajdować czwiczenia które zostały wykonywane na Laboratoriach z przedmiotu NAI

  ## Lab_01 13.10.2020
    Niech program który jest w Twoim repozytorium będzie wyświetlał odbicie lustrzane tego co widzi kamerka.
    Niech też program się zakończy w momencie wciśnięcia klawisza ESC

  ## Lab_02 20.10.2020
    Pobierze z kamery klatkę obrazu
    Rozmyje obraz za pomocą rozmycia Gaussa (parametry wybierz sobie takie, jak Tobie wydadzą się odpowiednie)
    Przeskaluje ją do rozmiaru takiego, jak podany w argumencie wywołania Twojego programu (czyli będzie można z linii komend powiedzieć jak wielki ma być obrazek).
    Jeśli nie  podano argumentów, niech będzie to 320x200
    Przekształci przestrzeń barw do formatu HSV (niech to pojawia się w okienku)
    Dokona operacji inRange dla zadanych zakresów - zakresy niech będą podane za pomocą suwaków. (to będzie drugie okienko)
    Wartości zakresów niech pojawiają się w okienku z obrazem w wersji HSV
    Jeżeli użytkownik naciśnie klawisz <x> to zostanie zrobione "zdjęcie" wybranego przez użytkownika fragmentu obrazu - wybieramy ROI.
    To zdjęcie niech zostanie zapisane na dysk pod nazwą taką, jak sobie wymyślisz. Podpowiem, że można skorzystać z imwrite

  ## Lab_03 27.10.2020
    Napisz program, który będzie wyłapywał 2 największe obiekty wybranego koloru (wybierz kolor, polecam kolory bardzo jaskrawe) i jak zostaną ułożone w jednej lini (z jakimś marginesem) to między nimi zostanie narysowane coś. 
    Niech to coś będzie w stylu (do wyboru) odcinek, obrazek pioruna, obrazek miecza świetlnego, czy czegokolwiek innego.
  
  ## Lab_04 03.11.2020
    Wyobraźmy sobie, że mamy do zeskanowania dokument. Chcielibyśmy, aby zawsze był on poprawnie zorientowany (góra u góry, dół na dole, a nie do góry nogami). 
    Nie mamy skanera, więc musimy skorzystać z aparatu w telefonie lub w laptopie.
    Zasada działania: Użytkownik kładzie kartkę do "zeskanowania" na ciemnym stole, a następnie kładzie na kartce marker (na przykład coś o kolorze różowym) w prawym dolnym rogu tej kartki. Kieruje kamerę na tą kartkę.
    Program wyłapuje prostokątną kartkę papieru, sprawdza czy jest na niej marker, jeśli tak, to robi zdjęcie, poprawiaperspekty tak aby kartka była prostokątna obraca jeśli trzeba tak aby marker był na dole i zapisuje na dysku.
    Może zapisywać na przykład serię tak zeskanowanych kartek w celu umożliwienia użytkownikowi wyboru najlepszego skanu.                                                
                                                
  ## Lab_05 10.11.2020
    Zapoznaj się z dostępnymi kaskadami. Wybierz jedną (inną niż twarz). 
    Napisz program, który będzie zliczał ile razy pojawił się dany obiekt w obiektywie kamery. 
    
    Jeśli nie jesteś w stanie wybrać/przetestować innej kaskady, to można zrobić dzisiejsze ćwiczenie na 75% z wykorzystaniem tej kaskady która była na wykładzie.
    - niech to rejestruje poprawnie sytuacje, gdy jest widoczny tylko jeden obiekt na raz.
    - program pozwala na zliczanie dowolnie wielu obiektów na raz.
 
  ## Lab_06 17.11.2020
    Zaimplementuj w wybranym przez ciebie języku programowania ogólny interfejs reprezentujący dowolną taką funkcję, z https://en.wikipedia.org/wiki/Test_functions_for_optimization
    Zaimplementuj kilka wybranych przez Ciebie funkcji testowych (co najmniej 3).
    Zaimplementuj funkcję, która będzie znajdywała przybliżone rozwiązanie dla dowolnej z zaimplementowanych funkcji. Zrób to w następujący sposób:
    Zaimplementuj funkcję (lub metodę), która będzie pobierała jako argument funkcję do zoptymalizowania oraz zakres dziedziny. Funkcja ta będzie wykonywała losowe próbkowanie punktów dziedziny w celu znalezienia takiego, dla którego wartość funkcji celu będzie najlepsza.
    
    *Przygotuj wykres, pokazujący jakość rozwiązania w stosunku do czasu obliczeń. Uśrednij go z 20 eksperymentów. 
    Jeśli nie masz pomysłu jak wygenerować wykres - skorzystaj z Gnuplot-a.
    
  ## Lab_07 24.11.2020 
    Zaimplementuj zrandomizowany algorytm wspinaczkowy, który będzie przyjmował jako argument wywołania funkcję optymalizowaną oraz ograniczenia kostkowe dziedziny.
    Niech punkt startu będzie wybierany losowo z dziedziny.
    Przetestuj dla wszystkich funkcji które zostały zaimplementowane w poprzednim tygodniu.
    Najlepiej aby można było wybierać funkcję (może po nazwie) oraz jej parametry z linii komend.

    *Tak jak poprzednio - przygotuj wykres pokazujący jak przebiega postęp obliczeń. Tym razem spróbuj uśrednić wyniki z kilku (co najmniej pięciu) wywołań eksperymentu.
    
  ## Lab_08 01.12.2020 
    Zaimplementuj zadanie optymalizacyjne tak, aby można było je liczyć za pomocą algorytmu genetycznego. Teraz bardziej szczegółowo:
 
    Wybierz jedno z zadań optymalizacyjnych, ale tylko takie które ma wiele minimów lokalnych.
    Na potrzeby ćwiczeń zmienne z dziedziny funkcji nazwę X oraz Y, ale oczywiście jeśli wybrana została przez Ciebie funkcja która przyjmuje więcej argumentów, to oczywiście będzie tu X0, X1, .. Xn
    
    Przygotuj funkcję która przekształci tablicę 128 liczb ze zbioru {0,1} na odpowiednio X oraz Y. 
    Na dodatkowy punkt - niech będzie to liczba w kodzie Greay-a (https://pl.wikipedia.org/wiki/Kod_Graya). 
    To będzie funkcja dekodująca genotyp do postaci fenotypu (czyli tak jak to na wykładzie było - ciąg kodowy w konkretne rozwiązanie).Pamiętaj o ułamkach!
	Napisz funkcję oceny (inaczej funkcję fitness), która będzie oceniała fenotyp. W tym celu należy zrobić funkcję, która będzie na przykład odwracała funkcję celu (funkcje testowe do optymalizacji są minimalizowane, a funkcja oceny jest maksymalizowana, więc trzeba przekształcić jedną w drugą). 
    Przy tym punkcie zachęcam do zadawania pytań.
	  Przetestuj ręcznie, czy faktycznie to działa. Dodaj możliwość konwersji genotypu w fenotyp oraz fenotypu w genotyp. (czyli tablica 128 liczb na X,Y oraz z X,Y na tablicę 128 liczb).
	  Przetestuj, czy algorytm losowego próbkowania da radę tu wygenerować jakieś sensowne rozwiązanie. - to na dodatkowe 0.5pkt

  ## Lab_09 08.12.202
  	Napisz operatory genetyczne.
	Masz już przygotowane elementy zadania optymalizacyjnego do rozwiązania przez GA. Teraz czas na operatory genetyczne. Przygotuj i przetestuj:
	Krzyżowanie jednopunktowe
	Mutacja (wybierz)
	Selekcja turniejowa albo ruletkowa
	Tak więc po tych zajęciach powinno być prawie wszystko – bez samej głównej pętli algorytmu. To zrobimy na następnym naszym spotkaniu
  
  ## Lab_10 15.12.2020
 	Dziś dokańczamy algorytm genetyczny. Przygotuj główną pętlę tego algorytmu. Przypominam etapy:
	Inicjalizacja populacji
	Powtarzanie dopóki nie nastąpi warunek zakończenia
		selekcja
		krzyżowanie
		mutacja
		tworzenie nowej populacji (to na dodatkowy punkt można uwzględnić elitę)
	wynik to najlepszy osobnik z bieżącej populacji
 
  ## Lab_11 22.12.2020
  	Sieci neuronowe
	Zadanie na dziś:
	Przygotuj implementację sztucznego neuronu. Miej na uwadze fakt, że będzie trzeba je połączyć ze sobą na przyszłych zajęciach.
	Można spróbować funkcyjnie, ale tu będzie trochę gimnastyki.
  
  ## Lab_12 12.01.2021
  	Sztuczne sieci neuronowe
	Na dzisiaj proponuję przygotować małą sieć neuronową.
	Wypisywanie informacji dla nas

	Dodaj funkcję lub metodę pozwalającą na wypisanie parametrów neuronu.

	Implementacja mini sieci neuronowej

	Zaimplementuj sieć neuronową składającą się z 3 neuronów. Niech będą one połączone w następujący sposób:

	-- N1 -
     	  \
    	    -- N3 --
     	  /
	-- N2 -


	Wypisanie stanu

	Dodaj możliwość wyświetlenia stanu tej sieci neuronowej, to znaczy:


	
	Wejścia
	Wagi wejść
	Wartość sumy ważonej wejść
	Stan neuronu (wzbudzony lub nie, ewentualnie wartość po obliczeniu funkcji aktywacji)
	Wyświetlenie listy połączeń między neuronami (metoda dowolna)


	Zadanie na dodatkowy punkt
	Wyeksportuj sieć neuronową do formatu graficznego lub grafu. Może być też format graphviz i przykład wizualizacji.
  
  ## Lab_13 19.01.2021
  
  ## Lab_14 26.01.2021
  
  ## Lab_15 02.02.2021
  
  
  
	  
