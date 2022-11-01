/* Fakta */
car(maserati,green,25000).
car(corvette,black,24000).
car(corvette,red,26000).
car(corvette,red,23000).
car(porsche,red,24000).
colors(red,sexy).
colors(black,mean).
colors(green,preppy).

/* ATURAN */
buy_car(Model,Color):-
    car(Model,Color,Price),colors(Color,sexy),!,Price < 25000.