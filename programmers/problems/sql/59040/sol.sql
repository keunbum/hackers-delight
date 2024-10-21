SELECT animal_type, COUNT(*) AS type_cnt
FROM ANIMAL_INS
GROUP BY animal_type
ORDER BY animal_type;