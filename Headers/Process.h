class Process {
    private:
        int process_id;
        float arrival_time;
        float burst_time;
        int priority;
        float waiting_time;
    public:
        Process(int process_id, int arrival_time, int burst_time, int priority=0);

        // * Getters ---------------------------
        int getProcess_id() const;
        float getArrival_time() const;
        float getBurst_time() const;
        int getPriority() const;
        float getWaiting_time() const;

        // * Setters ---------------------------
        void setWaiting_time(int time);

};