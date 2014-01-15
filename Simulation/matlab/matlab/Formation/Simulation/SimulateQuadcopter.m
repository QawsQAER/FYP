function [ next_vel, new_integral ] = SimulateQuadcopter(now_pos,now_vel,waypoint,old_vel,integral,number)
%   this function simulates the behavior of one single quadcopter
%   Detailed explanation goes here
%   waypoint = [quadnum, target x, target y]
    dummy = [];
    P = 0.09;
    I = 1;
    D = 0.5;
    delay = 0.25;
    
    difference = waypoint(2:3) - now_pos(2:3); 
    difference_vel = old_vel - now_vel(2:3);

    acceleration = P.* difference + I.* integral + D.*difference_vel;    
    

    new_integral = integral + difference;
    next_vel = [number now_vel(2:3) + (acceleration +  randn(1,2).* 0.35).* delay] ;
    %{
    if(number == 2)
    fprintf('The %d_th quadcopter\n',number);
    difference
    now_pos
    now_vel
    waypoint
    acceleration
    next_vel
    fprintf('--------------------------------\n');
    %fprintf('target x, y [%f %f]',waypoint(2),waypoint(3));
    %fprintf('[%f %f]\n',next_vel(1),next_vel(2));
    %fprintf('now velo is [%f %f]',now_vel(1),now_vel(2));
    %fprintf('acceleration is [%f %f]\n',acceleration(1),acceleration(2));
    end
    %}
end

