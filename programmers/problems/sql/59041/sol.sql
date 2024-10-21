SELECT name, COUNT(name) AS name_cnt
FROM ANIMAL_INS
GROUP BY name
HAVING COUNT(name) >= 2
ORDER BY name;