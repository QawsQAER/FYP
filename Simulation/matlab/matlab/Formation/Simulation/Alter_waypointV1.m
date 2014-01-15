function [left_waypoint,right_waypoint,left,right] = Alter_waypointV1(NO,PATH,Set_of_Quadcopter,Waypoint,Position)
%UNTITLED3 Summary of this function goes here
%   Detailed explanation goes here

    for count = 1:length(Set_of_Quadcopter)
    {    
        num = Set_of_Quadcopter(count);
        %fprintf('number is %d\n',x);
        path1 = [Waypoint(num,1),Waypoint(num,2), Position(num,1), Position(num,2)];
        result = lineSegmentIntersect(path1,PATH);
        if(result.intAdjacencyMatrix != 1)
        {
            fprintf
        }
        end
    }
    end % end for
   
    dummy = 1;
    left = dummy;
    right = dummy;
    left_waypoint = dummy;
    right_waypoint = dummy;
end

