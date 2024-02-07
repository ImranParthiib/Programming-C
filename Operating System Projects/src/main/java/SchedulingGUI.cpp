#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <chrono>

class Job;

class SchedulingGUI : public JFrame
{
private:
    std::string algorithms[4] = {"FCFS", "Round Robin", "Shortest Job First", "Priority Scheduling"};
    std::string sourcePath;
    static int NUM_OF_PROCESSES;
    static std::string selectedAlgo;

    javax.swing.JPanel jPanel1;
    javax.swing.JLabel jLabel2;
    javax.swing.JComboBox<String> jComboBox1;
    javax.swing.JLabel jLabel3;
    javax.swing.JButton jButton1;
    javax.swing.JButton jButton2;
    javax.swing.JLabel jLabel4;
    javax.swing.JLabel jLabel1;
    javax.swing.JLabel jLabel5;
    javax.swing.JTextField jTextField1;
    javax.swing.JButton nextStep2;
    javax.swing.JLabel jLabel6;
    javax.swing.JLabel jLabel7;

public:
    SchedulingGUI()
    {
        initComponents();
        jLabel7.setIcon(new javax.swing.ImageIcon("src/main/java/dark-abstract-tech-background_53876-90630.jpg"));
        setResizable(false);
        setTitle("CPU Scheduling Simulator");
        jComboBox1.setModel(new DefaultComboBoxModel<>(algorithms));
        addWindowListener(new WindowListener());
        setLocationRelativeTo(null);
    }

private:
    class WindowListener : public WindowAdapter
    {
    public:
        void windowOpened(WindowEvent e)
        {
            TitleThread thread = new TitleThread("Simulation", jLabel1, 200);
            thread.start();
        }
    };

    void initComponents()
    {
        // Generated GUI code
        // ...
    }

    void jButton1ActionPerformed(java.awt.event.ActionEvent evt)
    {
        JFileChooser fileChooser = new JFileChooser();
        fileChooser.showOpenDialog(null);
        File file = fileChooser.getSelectedFile();
        sourcePath = file.getAbsolutePath();
    }

    void jButton2ActionPerformed(java.awt.event.ActionEvent evt)
    {
        JOptionPane.showMessageDialog(null, "Developers:\n\nAmmar Ahmed, BSCS-IV.\nSuraksha Sadhwani, BSCS-IV.");
    }

    void nextStep2ActionPerformed(java.awt.event.ActionEvent evt)
    {
        int numOfProcesses = Integer.parseInt(jTextField1.getText());
        if (sourcePath.empty())
            JOptionPane.showMessageDialog(null, "ERROR: Please input the source of computation");
        else if (numOfProcesses <= 0)
            JOptionPane.showMessageDialog(null, "ERROR: Please input the appropriate number of processes");
        else
        {
            selectedAlgo = jComboBox1.getSelectedItem().toString();
            NUM_OF_PROCESSES = std::stoi(jTextField1.getText());
            std::vector<Job *> jobs(NUM_OF_PROCESSES);
            for (int i = 1; i <= NUM_OF_PROCESSES; i++)
            {
                std::string processID = "P" + std::to_string(i);
                long arrivalTime = (std::rand() % 9 + 1) * 300;
                long burstTime = (std::rand() % 3 + 1) * 100;
                long STRTTIME = std::chrono::high_resolution_clock::now().time_since_epoch().count();

                Job *newJob = new Job(processID, arrivalTime, burstTime, STRTTIME);
                jobs[i - 1] = newJob;
            }
            CalcSimulation *sim = new CalcSimulation(jobs, NUM_OF_PROCESSES, sourcePath, selectedAlgo);
            sim->start();
            this->dispose();
        }
    }

public:
    static void main(std::string args[])
    {
        try
        {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels())
            {
                if ("Nimbus".equals(info.getName()))
                {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        }
        catch (ClassNotFoundException ex)
        {
            java.util.logging.Logger.getLogger(SchedulingGUI.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        catch (InstantiationException ex)
        {
            java.util.logging.Logger.getLogger(SchedulingGUI.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        catch (IllegalAccessException ex)
        {
            java.util.logging.Logger.getLogger(SchedulingGUI.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        catch (javax.swing.UnsupportedLookAndFeelException ex)
        {
            java.util.logging.Logger.getLogger(SchedulingGUI.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new SchedulingGUI().setVisible(true);
    }
        });
        }
        }
        ;
