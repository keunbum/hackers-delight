SELECT EXTRACT(hour FROM datetime) AS my_hour, COUNT(*) AS cnt_hours
FROM ANIMAL_OUTS
WHERE EXTRACT(hour FROM datetime) BETWEEN 9 AND 19
GROUP BY EXTRACT(hour FROM datetime)
ORDER BY my_hour, cnt_hours;