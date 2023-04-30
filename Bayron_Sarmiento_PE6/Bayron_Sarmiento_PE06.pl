% Name: Sean Gabriel Bayron
% Student Number: 2021-04354
% Name: Arnel Jan Sarmiento
% Student Number: 2021-05094
% Date: 2023-4-30
% This program is a Prolog Database for the problem Detective Mori deduces the identity of the one who killed the legendary Hollywood actor
% The program was developed by Sean Gabriel Bayron and Arnel Jan Sarmiento.

location(nobita, 25). % Nobita was in room 25
location(kudo, 29). % Kudo was in room 29
location(conan, 23). % Conan was in room 23
location(X, 27) :- costume(X, 'G-Shock'). % If the person was wearing a G-Shock, then he was in room 27
costume(nobita, pendant). % Nobita had a pendant
costume(pope, 'G-Shock'). % Pope had a G-Shock
costume(X, fancy_bracelet) :- location(X, 23). % A person has a fancy bracelet if they were in room 23
costume(conan, shades) :- costume(kudo, fancy_bracelet). % If Kudo had a fancy bracelet, then Conan wore the shades and vice versa
costume(kudo, shades) :- costume(conan, fancy_bracelet).

eyebrows(X, pink) :- costume(X, shades). % A person has pink eyebrows if they wore the shades
eyebrows(X, yellow) :- costume(X, fancy_bracelet). % A person has yellow eyebrows if they wore a fancy bracelet
eyebrows(X, brown) :- location(X, 27). % A person has brown eyebrows if they were in room 27
eyebrows(X, silver) :- location(X, 25). % A person has silver eyebrows if they were in room 25

slayer(X) :- eyebrows(X, pink). % The slayer had pink eyebrows