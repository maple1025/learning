-- test scripts for foods.db, come from book Sqlite: the definitive guide
.echo on
.mode column
.headers on
.nullvalue NULL

select *
from foods
where name='JujyFruit'
and type_id=9;

select f.name name, types.name type
from foods f
inner join (
    select *
    from food_types
    where id=6) types
on f.type_id=types.id;

select * from foods
where name like 'B%'
order by type_id desc, name limit 10;

select id, upper(name), length(name)
from foods
where type_id=1 limit 10;

select count(*)
from foods where type_id=1;

select type_id
from foods
group by type_id;

select type_id, count(*)
from foods
group by type_id;

select distinct type_id from foods;

select foods.name, food_types.name
from foods, food_types
where foods.type_id=food_types.id;

select *
from foods inner join food_types
on foods.type_id = food_types.id;

select f.name as food, e1.name, e1.season, e2.name, e2.season
from episodes e1, foods_episodes fe1, foods f,
     episodes e2, foods_episodes fe2
where 
    -- Get foods in season 4
    (e1.id = fe1.episode_id and e1.season = 4) and fe1.food_id = f.id
    -- Link foods wiht all other episodes
    and (fe1.food_id = fe2.food_id)
    -- Link with their respective episodes and filter out e1's season
    and (fe2.episode_id = e2.id and e2.season != e1.season)
order by f.name;

select f.*, top_foods.count from foods f
inner join
    (select food_id, count(food_id) as count from foods_episodes
        group by food_id
        order by count(food_id) desc limit 1) top_foods
    on f.id=top_foods.food_id
union
select f.*, bottom_foods.count from foods f
inner join
    (select food_id, count(food_id) as count from foods_episodes
        group by food_id
        order by count(food_id) limit 1) bottom_foods
    on f.id=bottom_foods.food_id
order by top_foods.count desc;

select f.* from foods f
inner join
    (select food_id, count(food_id) as count
        from foods_episodes
        group by food_id
        order by count(food_id) desc limit 10) top_foods
    on f.id=top_foods.food_id
intersect
select f.* from foods f
    inner join foods_episodes fe on f.id = fe.food_id
    inner join episodes e on fe.episode_id = e.id
    where e.season betwren 3 and 5
order by f.name;

select name || case type_id
                    when 7 then ' is a drink'
                    when 8 then ' is a fruit'
                    when 9 then ' is junkfood'
                    when 13 then ' is seafood'
                    else null
                end description
from foods
where description is not null
order by name
limit 10;

select name, (select
                case
                    when count(*) > 4 then 'Very High'
                    when count(*) = 4 then 'High'
                    when count(*) in (2,3) then 'Moderate'
                    else 'Low'
                end
            from foods_episodes
            where food_id=f.id) frequency
from foods f
where frequency like '%High';

update foods set name='CHOCOLATE BOBKA'
where name='Chocolate Bobka';
select * from foods where name like 'CHOCOLATE%';
