
%Facts
fact('Sun rises in the East').

rainy(seattle).
rainy(rochester).
cold(rochester).



%Rules
snowy(X) :- rainy(X), cold(X).

rainy(X) :- rainy(Y).
rainy(Y) :- rainy(Z).

