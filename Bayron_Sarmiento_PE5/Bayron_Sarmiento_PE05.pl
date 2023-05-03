# Gender Facts
male(IndalecioSr).
male(Richardo).
male(Dante).
male(Gilbert).
male(IndalecioJr).
male(Walter).
male(Nolly).
male(Saturnino).
male(Sean).
male(Paul).
male(DJ).
male(Kelvin).
female(Tiburcia).
female(Nelly).
female(Genevieve).
female(Emily).
female(Lilly).
female(Mary).
female(Angela).
female(Sophia).

# Paternal Side
parent(IndalecioSr, Dante).
parent(IndalecioSr, Gilbert).
parent(IndalecioSr, IndalecioJr).
parent(IndalecioSr, Genevieve).
parent(IndalecioSr, Walter).
parent(Tiburcia, Dante).
parent(Tiburcia, Gilbert).
parent(Tiburcia, IndalecioJr).
parent(Tiburcia, Genevieve).
parent(Tiburcia, Walter).

# Maternal Side
parent(Ricardo, Emily).
parent(Ricardo, Lilly).
parent(Ricardo, Nolly).
parent(Ricardo, Mary).
parent(Ricardo, Lanie).
parent(Nelly, Emily).
parent(Nelly, Lilly).
parent(Nelly, Nolly).
parent(Nelly, Mary).
parent(Nelly, Lanie).

# Gilbert and Lilly Children
parent(Gilbert, Sean).
parent(Gilbert, Angela).
parent(Gilbert, Paul).
parent(Lilly, Sean).
parent(Lilly, Angela).
parent(Lilly, Paul).

# Saturnino and Lanie Children
parent(Saturnino, DJ).
parent(Saturnino, Sophia).
parent(Saturnino, Kelvin).
parent(Lanie, DJ).
parent(Lanie, Sophia).
parent(Lanie, Kelvin).

# IndalecioSr and Tiburcia Grandchildren
grandparent(IndalecioSr, Sean).
grandparent(IndalecioSr, Angela).
grandparent(IndalecioSr, Paul).
grandparent(Tiburcia, Sean).
grandparent(Tiburcia, Angela).
grandparent(Tiburcia, Paul).


# Richardo and Nelly Grandchildren
grandparent(Ricardo, Sean).
grandparent(Ricardo, Angela).
grandparent(Ricardo, Paul).
grandparent(Ricardo, DJ).
grandparent(Ricardo, Sophia).
grandparent(Ricardo, Kelvin).
grandparent(Nelly, Sean).
grandparent(Nelly, Angela).
grandparent(Nelly, Paul).
grandparent(Nelly, DJ).
grandparent(Nelly, Sophia).
grandparent(Nelly, Kelvin).

# Rules
granpa(X,Y) :- male(X), parent(X,Z), parent(Z,Y).
granma(X,Y) :- female(X), parent(X,Z), parent(Z,Y).

father(X,Y) :- male(X), parent(X,Y).
mother(X,Y) :- female(X), parent(X,Y).

son(X,Y) :- male(X), parent(Y,X).
daughter(X,Y) :- female(X), parent(Y,X).

sibling(X,Y) :- parent(Z,X), parent(Z,Y), X \= Y.

aunt(X,Y) :- female(X), sibling(X,Z), parent(Z,Y).
uncle(X,Y) :- male(X), sibling(X,Z), parent(Z,Y).

cousin(X,Y) :- parent(Z,X), sibling(Z,W), parent(W,Y).