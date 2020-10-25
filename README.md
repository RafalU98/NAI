# NAI
Czwiczenia z NAI PJATK-Gdańsk 2020

Tutaj bedą się znajdować czwiczenia które zostały wykonywane na Laboratoriach z przedmiotu NAI

                                                Lab1 13.10.2020
Niech program który jest w Twoim repozytorium będzie wyświetlał odbicie lustrzane tego co widzi kamerka.
Niech też program się zakończy w momencie wciśnięcia klawisza ESC

                                                Lab2 20.10.2020
Pobierze z kamery klatkę obrazu
Rozmyje obraz za pomocą rozmycia Gaussa (parametry wybierz sobie takie, jak Tobie wydadzą się odpowiednie)
Przeskaluje ją do rozmiaru takiego, jak podany w argumencie wywołania Twojego programu (czyli będzie można z linii komend powiedzieć jak wielki ma być obrazek). Jeśli nie podano argumentów, niech będzie to 320x200
Przekształci przestrzeń barw do formatu HSV (niech to pojawia się w okienku)
Dokona operacji inRange dla zadanych zakresów - zakresy niech będą podane za pomocą suwaków. (to będzie drugie okienko)
Wartości zakresów niech pojawiają się w okienku z obrazem w wersji HSV
Jeżeli użytkownik naciśnie klawisz <x> to zostanie zrobione "zdjęcie" wybranego przez użytkownika fragmentu obrazu - wybieramy ROI. To zdjęcie niech zostanie zapisane na dysk pod nazwą taką, jak sobie wymyślisz. Podpowiem, że można skorzystać z imwrite

