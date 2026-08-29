# Write your MySQL query statement below
SELECT 
    c.visited_on,
    (
        SELECT SUM(a.amount)
        FROM Customer a
        WHERE a.visited_on <= c.visited_on AND DATEDIFF(c.visited_on, a.visited_on) <7
    ) AS amount,
    ROUND(
        (
            SELECT SUM(a.amount)
            FROM Customer a
            WHERE a.visited_on <= c.visited_on AND DATEDIFF(c.visited_on, a.visited_on) <7
        
        ) / 7,
        2
    ) AS average_amount
FROM Customer c
WHERE c.visited_on >= (
    SELECT DATE_ADD(MIN(visited_on), INTERVAL 6 DAY)
    FROM Customer
)
GROUP BY c.visited_on
ORDER BY c.visited_on;