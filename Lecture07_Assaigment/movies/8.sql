SELECT name FROM people JOIN stars ON stars.person_id = people.id WHERE stars.movie_id = (SELECT id FROM movies WHERE title LIKE 'Toy Story');
