class Process {
    private:
        int process_id;
        float arrival_time;
        float burst_time;
        int priority;
        float waiting_time;
        float turnaround_time;
        float total_burst_time;
    public:
        Process(int process_id, int arrival_time, int burst_time, int priority=0);
        Process(){}

        // * Getters ---------------------------
        int getProcess_id() const;
        float getArrival_time() const;
        float getBurst_time() const;
        int getPriority() const;
        float getWaiting_time() const;
        float getTurnaround_time() const;
        float getTotal_Burst_time() const;

        // * Setters ---------------------------
        void setWaiting_time(int time);
        void setTurnaround_time(float time);
        void setBurst_time(float time);

};
