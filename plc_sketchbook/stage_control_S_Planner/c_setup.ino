// ------
// Setup
// ------

void setup() {

  // Initialize Serial Comm Sockets
  Serial.begin(115200);
  Serial.println("Setup Process Complete");

  // Initializes the P1AM communications to the P1 modules
  // P1.init(); //returns type uint8_t for diagnostic. Implement?
  while (!P1.init()) {
    delay(100); //Wait for Modules to Sign on  
  }

  //Initialize Ethernet
  //Serial.println("Setup Configuration: Network enabled. Will now attempt to connect to network");
  //Ethernet.begin(mac);
  // setup_ethernet();

  // Initialize Stage and Sensor
  set_stage_power(true);
  set_distance_sensor_power(true);

  // Exteneral Remote Control Indicator
  pinMode(LED_BUILTIN, OUTPUT);

  // Report Setup Success
  Serial.println("Setup Process Complete");


  // Calculate S Curve Offsets

// Perform Initial Calculations
int j = max_a / time_to_max_a;
int x0 = 100;
int xf = 0;
xf = xf - x0;

// Unused Short Profile Calculations
// short_profile = max_v * (time_to_max_a + max_v / max_a) > xf
// if short_profile
//     profile_max_v = max_a * (sqrt(xf / max_a - 0.75 * time_to_max_a^2) - 0.5 * time_to_max_a);
// else
//     profile_max_v = max_v;
// end

int profile_max_v = max_v;

//////////////////////////////////////////////////////////////
// Find times at critical points
//////////////////////////////////////////////////////////////

int t2 = profile_max_v / max_a;
int t3 = t2 + time_to_max_a;

// Unused Code
// if short_profile
//     t4 = t3
// else
//     t4 = xf / profile_max_v
// end
int t4 = abs(xf) / profile_max_v;

int t5 = t4 + time_to_max_a;
int t6 = t4 + t2;
int t7 = t6 + time_to_max_a;
int time_total = t7;
timestamps[1] = time_to_max_a;
timestamps[2] = t2;
timestamps[3] = t3;
timestamps[4] = t4;
timestamps[5] = t5;
timestamps[6] = t6;
timestamps[7] = t7;


//////////////////////////////////////////////////
// Calculate Short Profile
//////////////////////////////////////////////////
int dt = PLC_dt; //So we can plot a much more specific curve to see whatprofile actually looks like
int t_rec_S[time_total/dt];
int x_rec_S[time_total/dt];
int v_rec_S[time_total/dt];
int a_rec_S[time_total/dt];
x_rec_S[0] = x0;
int t = 0;
Serial.println(time_total);
Serial.println(time_total/dt);

while (t < time_total) {
    t = t + 1;
    t_rec_S[t] = (t-1)*dt;
    if (t_rec_S[t] < time_to_max_a) {
        // Ramp up acceleration
        a_rec_S[t] = (j * t_rec_S[t]);
        v_rec_S[t] = (0.5 * j * t_rec_S[t] * t_rec_S[t]);
    } else if (t_rec_S[t] < t2) {
        // Increase speed at max acceleration
        a_rec_S[t] = (max_a);
        v_rec_S[t] = (max_a * (t_rec_S[t] - 0.5 * time_to_max_a));
    } else if (t_rec_S[t] < t3) {
        // Ramp down acceleration
        a_rec_S[t] = (max_a - j * (t_rec_S[t] - t2));
        v_rec_S[t] = (max_a * (t_rec_S[t] - 0.5 * time_to_max_a ) - 0.5 * j * (t_rec_S[t] - t2) * (t_rec_S[t] - t2));
    } else if (t_rec_S[t] < t4) {
        // Maintain max velocity
        a_rec_S[t] = 0;
        v_rec_S[t] = profile_max_v;
    } else if (t_rec_S[t] < t5) {
        // Ramp down acceleration
        a_rec_S[t] = (-j * (t_rec_S[t] - t4));
        v_rec_S[t] = ( profile_max_v - 0.5 * j * (t_rec_S[t] - t4) * (t_rec_S[t] - t4));
    } else if (t_rec_S[t] < t6) {
        // Decrease speed at max acceleration
        a_rec_S[t] = (-max_a);
        v_rec_S[t] = (max_a * (t2 + t5 - t_rec_S[t] - 0.5 * time_to_max_a));
    } else if (t_rec_S[t] < t7) {
        // Ramp up acceleration
        a_rec_S[t] = (-max_a + j * (t_rec_S[t] - t6));
        v_rec_S[t] = (max_a * (t2 + t5 - t_rec_S[t] - 0.5 * time_to_max_a) + 0.5 * j * (t_rec_S[t] - t6) * (t_rec_S[t] - t6));
    } else {
        a_rec_S[t] = (0.0);
        v_rec_S[t] = (0.0);
    }

    a_rec_S[t] = a_rec_S[t]; // *sign(xf)
    v_rec_S[t] = v_rec_S[t]; // *sign(xf)
    x_rec_S[t] = (x_rec_S[t-1] + v_rec_S[t-1] * dt);
    Serial.print(x_rec_S[t]); Serial.print(" | "); Serial.print(v_rec_S[t]); Serial.print(" | "); Serial.println(a_rec_S[t]);
}

}
