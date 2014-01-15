function [ Exp_pos ] = CalculateExpectPosition( now_pos,now_vel,delay )
%UNTITLED5 Summary of this function goes here
%   Detailed explanation goes here
    now_pos;
    now_vel;
    Exp_pos = now_pos;
    Exp_pos(1:end,2:3)
    now_vel;
    Exp_pos(1:end,2:3) = Exp_pos(1:end,2:3) + now_vel(1:end,2:3).* delay;
end

