%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Code written by Wyatt Kromer
% 
% The purpose of this script is to calculate the setpoints of curves ahead
% of time so that the Arduino PLC doesn't have to do any complex
% calculations at runtime.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
clear all
clc

%% S-Curve
% Note that this scheme will utilize a deadband in order to eliminate the
% possibility of short profiles where the stage does not reach max_v
% This could be changed if necessary for speed

%%%%%%%%%%%%%%%%%%
% Input Parameters
%%%%%%%%%%%%%%%%%%

max_v = 2;              % m/s
max_a = .05;              % m/s
time_to_max_a = .5;      % s
PLC_dt = 0.01;          % s
goal = 1000;               % m
deadband_distance = 0; % m, and this is for a single direction. Deadband is actually twice as wide

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Perform Initial Calculations
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

j = max_a / time_to_max_a;

% Unused Short Profile Calculations
% short_profile = max_v * (time_to_max_a + max_v / max_a) > goal
% if short_profile
%     profile_max_v = max_a * (sqrt(goal / max_a - 0.75 * time_to_max_a^2) - 0.5 * time_to_max_a);
% else
%     profile_max_v = max_v;
% end

profile_max_v = max_v;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Find times at critical points
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

t2 = profile_max_v / max_a;
t3 = t2 + time_to_max_a;

% Unused Code
% if short_profile
%     t4 = t3
% else
%     t4 = goal / profile_max_v
% end
t4 = goal / profile_max_v;

t5 = t4 + time_to_max_a;
t6 = t4 + t2;
t7 = t6 + time_to_max_a;
time_total = t7;

%%%%%%%%%%%%%%%%%%%
% Calculate Profile
%%%%%%%%%%%%%%%%%%%
dt = PLC_dt / 100; %So we can plot a much more specific curve to see whatprofile actually looks like
% t_rec = zeros(1,time_total/dt);
% x_rec = zeros(1,time_total/dt);
% v_rec = zeros(1,time_total/dt);
% a_rec = zeros(1,time_total/dt);

x_rec(1) = deadband_distance;
t = 1;
while t < time_total
    t = t + 1;
    t_rec(t) = t*dt;
    if t < time_to_max_a 
        % Ramp up acceleration
        a_rec(t) = (j * t_rec(t));
        v_rec(t) = (0.5 * j * t_rec(t)^2);
    elseif t < t2
        % Increase speed at max acceleration
        a_rec(t) = (max_a);
        v_rec(t) = (max_a * (t - 0.5 * time_to_max_a ));
    elseif t < t3
        % Ramp down acceleration
        a_rec(t) = (max_a - j * (t_rec(t) - t2));
        v_rec(t) = (max_a * (t - 0.5 * time_to_max_a ) - 0.5 * j * (t_rec(t) - t2) ^ 2);
    elseif t < t4
        % Maintain max velocity
        a_rec(t) = (0.0);
        v_rec(t) = (profile_max_v);
    elseif t < t5
        % Ramp down acceleration
        a_rec(t) = (-j * (t_rec(t) - t4));
        v_rec(t) = ( profile_max_v - 0.5 * j * (t_rec(t) - t4) ^ 2);
    elseif t < t6
        % Decrease speed at max acceleration
        a_rec(t) = (-max_a);
        v_rec(t) = (max_a * (t2 + t5 - t_rec(t) - 0.5 * time_to_max_a));
    elseif t < t7
        % Ramp up acceleration
        a_rec(t) = (-max_a + j * (t_rec(t) - t6));
        v_rec(t) = (max_a * (t2 + t5 - t_rec(t) - 0.5 * time_to_max_a) + 0.5 * j * (t_rec(t) - t6) ^ 2);
    else
        a_rec(t) = (0.0);
        v_rec(t) = (0.0);
    end
    
    x_rec(t) = (x_rec(t-1) + v_rec(t-1) * dt);

    
end


% return t_rec , x_rec , v_rec , a_rec
figure
subplot(311)
plot(t_rec,x_rec,'LineWidth',2)
hold on
xline(time_to_max_a)
ylabel("Distance [m]")
xlabel("Time [s]")
subplot(312)
plot(t_rec,v_rec,'LineWidth',2)
xlabel("Distance [m]")
ylabel("Velocity [m/s]")
subplot(313)
plot(t_rec,a_rec,'LineWidth',2)
ylabel("Acceleration [m/s^2]")
xlabel("Time [s]")
xline(time_to_max_a)
