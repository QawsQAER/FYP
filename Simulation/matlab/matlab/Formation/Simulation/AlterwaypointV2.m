function [ temp_target ] = AlterwaypointV2(Exp_pos,waypoint,target_list);
%UNTITLED2 Summary of this function goes here
%   Detailed explanation goes here

    longest_path = waypoint(end,:);
    pos_of_quad = Exp_pos(longest_path(2),2:3);  % the position of the quadcopter of the longest path
    pos_of_targ = target_list(longest_path(3),2:3); % the position of the target of the longest path
    
    LR = [pos_of_quad, pos_of_targ];
    
    left_waypoint = []; % the list of path which lays on the right side of the longest path, the waypoint [distance, quad_num, target_num] is stored
    right_waypoint = []; % the list of path which lays on the left side of the longest path, the waypoint [distance, quad_num, target_num] is stored
    any_intersection = [];
    temp_path = [];
    
    %Compute the Equation for the line where the longest path stays as
    % Ax + By + C = 0
    toppoint = [];
    if((pos_of_quad(1) - pos_of_targ(1)) == 0)
        %case for vertical line
        A = 1;
        B = 0;
        C = pos_of_quad(1);
        %toppoint = [x1,0,x1,50];
        toppoint = [pos_of_quad(1), 0, pos_of_quad(1),50];
        
    else if((pos_of_quad(2) - pos_of_targ(2)) == 0)
        %case for horizontal line
        A = 1;
        B = 1;
        C = pos_of_quad(2);
        %toppoint = [0,y1,50,y1];
        toppoint = [0, pos_of_quad(2),50,pos_of_quad(2)];
        else
            %case for nomoral line
            A = 1;
            % B = (x2 - x1) / (y1 - y2); 
            B = (-1) .* (pos_of_quad(1) - pos_of_targ(1)) ./ (pos_of_quad(2) - pos_of_targ(2));
            % C = -x1 - B * y1 
            C = (-1) .* pos_of_quad(1) - B .* pos_of_quad(2);
            % y1 = -C / B when x = 0
            y1 = (-1) .* C  ./ B;
            % y2 = -50 C / B when x = 50
            y2 = ((-1).* C - 50)./ B;
            toppoint = [0,y1,50,y2];
        end
    end
    
        
    temp_target = [];
    standard_pos_of_targ = [];
    standard_pos_of_quad = [];
    for count = 1:(size(waypoint,1) - 1)
        standard_path = waypoint(count,:); %[distance, quad_num, target_num]
        
        standard_pos_of_quad = Exp_pos(standard_path(2),2:3)
        standard_pos_of_targ = target_list(standard_path(3),2:3)
        for count1 = (size(waypoint,1)- 1):count
            temp_path = waypoint(count1,:); %[distance, quad_num, target_num]
        
            temp_pos_of_quad = Exp_pos(temp_path(2),2:3);
            temp_pos_of_targ = target_list(temp_path(3),2:3);
            test_result = lineSegmentIntersect([standard_pos_of_quad, standard_pos_targ],[temp_pos_of_quad, temp_pos_of_targ]);
            if(test_result.intAdjacencyMatrix == 1)
                
                target_list(temp_path(3),2) = test_result.intMatrixX;
                target_list(temp_path(3),3) = test_result.intMatrixY;
            end 
        end
    end
    
    for count = 1:size(waypoint,1)
    temp_target = [temp_target;waypoint(count) target_list(count,2) target_list(count,3)];
    end
    
    
end

