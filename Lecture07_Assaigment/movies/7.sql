SELECT movies.title AS Title, ratings.rating AS Rating FROM movies JOIN ratings ON ratings.movie_id = movies.id WHERE year = 2010 ORDER BY rating DESC, title  ;
