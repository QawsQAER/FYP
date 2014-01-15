function [waypoint Best_target] = Path_Planning( now_pos,now_vel,target_list,delay )
%UNTITLED3 Summary of this function goes here
%   Detailed explanation goes here

    dummy = [1];
    fprintf('in path_planning\n');
    target_list;
    [waypoint Best_target] = Path_PlanningV2(now_pos,now_vel,target_list,delay);

end

