function [ new_vel ] = SimulateQuadcopterSwarm( now_pos,now_vel,waypoint,prev_vel,integral,number)
%  This fuction simulate the quadcopter swarm's behavior
%   Detailed explanation goes here

    new_vel = [];
    for count = 1:number
        %fprintf('Next Vel of %d is ',count);
        %extract the quad num for the row of record
        num = waypoint(count,1);
        
        %simulation of the num-th quadcopter
        [new_vel_temp,new_integral_temp] = SimulateQuadcopter(now_pos(num,:),now_vel(num,:),waypoint(count,:),prev_vel(num,:),integral(num,:),num);
        prev_vel(num,:) = now_vel(num,2:3);
        integral(num,:) = new_integral_temp;
        new_vel = [new_vel; new_vel_temp];
    end
    %sortrows(new_vel)
end

