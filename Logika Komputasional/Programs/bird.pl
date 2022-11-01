/*Fact*/
bird(sparrow).
bird(eagle).
bird(duck).
bird(crow).
bird(ostrich).
bird(puffin).
bird(swan).
bird(albatross).
bird(starling).
bird(owl).
bird(kingfisher).
bird(thrush).

/*Rule*/
can_fly(ostrich) :- !,fail.
can_fly(X):-bird(X).
