% gender facts
male(indaleciosr).
male(ricardo).
male(dante).
male(gilbert).
male(indaleciojr).
male(walter).
male(nolly).
male(saturnino).
male(sean).
male(paul).
male(dj).
male(kelvin).
female(tiburcia).
female(nelly).
female(genevieve).
female(emily).
female(lilly).
female(mary).
female(lanie).
female(angela).
female(sophia).

% paternal side
parent(indaleciosr, dante).
parent(indaleciosr, gilbert).
parent(indaleciosr, indaleciojr).
parent(indaleciosr, genevieve).
parent(indaleciosr, walter).
parent(tiburcia, dante).
parent(tiburcia, gilbert).
parent(tiburcia, indaleciojr).
parent(tiburcia, genevieve).
parent(tiburcia, walter).

% maternal side
parent(ricardo, emily).
parent(ricardo, lilly).
parent(ricardo, nolly).
parent(ricardo, mary).
parent(ricardo, lanie).
parent(nelly, emily).
parent(nelly, lilly).
parent(nelly, nolly).
parent(nelly, mary).
parent(nelly, lanie).

% gilbert and lilly children
parent(gilbert, sean).
parent(gilbert, angela).
parent(gilbert, paul).
parent(lilly, sean).
parent(lilly, angela).
parent(lilly, paul).

% saturnino and lanie children
parent(saturnino, dj).
parent(saturnino, sophia).
parent(saturnino, kelvin).
parent(lanie, dj).
parent(lanie, sophia).
parent(lanie, kelvin).

% indaleciosr and tiburcia grandchildren
grandparent(indaleciosr, sean).
grandparent(indaleciosr, angela).
grandparent(indaleciosr, paul).
grandparent(tiburcia, sean).
grandparent(tiburcia, angela).
grandparent(tiburcia, paul).


% ricardo and nelly grandchildren
grandparent(ricardo, sean).
grandparent(ricardo, angela).
grandparent(ricardo, paul).
grandparent(ricardo, dj).
grandparent(ricardo, sophia).
grandparent(ricardo, kelvin).
grandparent(nelly, sean).
grandparent(nelly, angela).
grandparent(nelly, paul).
grandparent(nelly, dj).
grandparent(nelly, sophia).
grandparent(nelly, kelvin).

% rules
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