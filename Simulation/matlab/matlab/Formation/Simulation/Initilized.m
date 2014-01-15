function [ now_pos,now_vel,target_list,waypoint ] = Initilized( number )
%UNTITLED2 Summary of this function goes here
%   Detailed explanation goes here
    target_list = [];
    dummy = [1];
    
    %inilized the position
    now_pos = [linspace(1,number,number)',rand(number,2).*50];
    %{
    if(number == 3)
     now_pos = [1.0000   25.7946   22.3345;
                2.0000   44.7713   24.3467;
                3.0000   11.0105   40.4857;];
    
    end
    if(number == 4)
        now_pos = [linspace(1,number,number)',[43.8786967153830,46.3147134098975;0.718107197299289,3.40902184135173;14.7151313423119,29.0546613789246;8.99574392521201,31.8575611262612;]];
    end
    %{
    if(number == 5)
        now_pos = [ 1.0000   45.2440   20.4360;
                    2.0000   48.9874   29.7448;
                    3.0000   21.9435   13.1106;
                    4.0000    5.5560   30.1422;
                    5.0000   12.9032   35.5608;];
    end
    %}
    
    %this set of data generated 2 intersection, one with the longest route
    %one not
    
    if(number == 6)
        now_pos = [1.0000   20.3810    5.2815;
                   2.0000   40.9991   30.5479;
                   3.0000   35.9179   38.9401;
                   4.0000   48.4325   21.1726;
                   5.0000   26.5667    4.5412;
                   6.0000   16.2573   13.3236];
    end
    
    %this set of data generated 1 intersection with the longest route
    %{
    if(number == 6)    
    now_pos = [
    1.0000    7.7376   15.9262;
    2.0000    9.9931   26.7032;
    3.0000   20.3477    4.4975;
    4.0000   37.4353    5.5853;
    5.0000   41.2792    6.8146;
    6.0000   39.4982   33.9326];
    end
    %}
    %}
    %inilized the velocity
    %now_vel = [linspace(1,number,number)',rand(number,2)]; random initial
    %speed
    now_vel = [linspace(1,number,number)',zeros(number,2)];
    
    
    target_list = [];
    %target_list = [linspace(0,50,number)',linspace(0,50,number)']
    if(number > 6)
        for count = 1:number
        target_list = [target_list; [count, sin(count / (2 * pi)).* 20 + 25 , cos(count / (2 * pi)).* 20 + 25]];
        end
    else if(number == 3)
        target_list = [1 16.67,15;2 33.22,15;3 25,40]; 
    else if(number == 4)
         target_list = [1 15,15;2 35,15;3 15,35;4 35,35];
        else if(number == 5)
         target_list = [1 25 40;2 40 25;3 30 10; 4 20 10;5 10 25];
            else if(number == 6)
                    target_list = [1 15 25;
                                   2 20 15;
                                   3 30 15;
                                   4 35 25;
                                   5 30 35;
                                   6 20 35;];
                end
            end
        end
        end
    end
    %fprintf('in initilization\n');
    target_list;
    %plot(target_list(1:end,1),target_list(1:end,2),'.');
    waypoint = zeros(number,2);

end

