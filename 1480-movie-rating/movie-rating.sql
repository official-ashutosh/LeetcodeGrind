# Write your MySQL query statement below
select (
    select u.name
    from Users u
    join MovieRating mr
    on u.user_id = mr.user_id
    group by u.user_id, u.name
    order by COUNT(*) desc, u.name
    limit 1
) AS results

union all

select (
    select m.title
    from Movies m
    join MovieRating mr
    on m.movie_id = mr.movie_id
    where date_format(mr.created_at, '%Y-%m') = '2020-02'
    group by m.movie_id, m.title
    order by AVG(mr.rating) desc, m.title
    limit 1
);