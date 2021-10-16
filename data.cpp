#include "data.hpp"

using namespace std; 

Set AlgorithmForNEMO( Set trails, int capacity){
    // S <- empty 
    Set sol({}), unassigned_flows = trails; 
    // c <- 0
    int cover_index = 0; 
    // CoveredBy(a) <- null, for each a in A
        // coveredBy = -1 for all arcs as default 
    // UF <- sort
        // sorted in ascending order by the length of each trail and,
        // in case of ties, in descending order by the sum of the number of trails covering ther arcs of each trail
    unassigned_flows.Sort(); 
    // for each f in UF do... 

    for(int flow=0; flow< unassigned_flows.Size(); flow++){     cout<<"1"<<endl; //DEBUG
        // h <- 0
        unassigned_flows.SetTrailHead(flow, 0);
        // t <- 0 
        unassigned_flows.SetTrailTail(flow, 0);
            // head and tail for each tail in unassigned_flows are already equal to EMPTY_TRAIL = 0
        // while t < |f| do... 
        while(unassigned_flows.GetTrailTail(flow) < unassigned_flows.GetTrailSize(flow)){ cout<<"2"<<endl; //DEBUG
            // g <- coveredBy(f(t))
            int aux = unassigned_flows.CoveredBy(flow, unassigned_flows.GetTrailTail(flow));
            // if g = null, then...
            if (aux == NO_COVER){cout<<"3"<<endl; //DEBUG
                // t <- t + 1
                unassigned_flows.SetTrailTail(flow, (unassigned_flows.GetTrailTail(flow) + 1));
            }
            // else...
            else{cout<<"4"<<endl; //DEBUG
                // if subtrail(S(g),f), then... 
                sol.GetTrailArcs(aux);
                unassigned_flows.GetTrailArcs(flow);
                if(IsSubtrail(sol.GetTrailArcs(aux), unassigned_flows.GetTrailArcs(flow))){cout<<"5"<<endl; //DEBUG
                    // t <- t + |S(g)|
                    unassigned_flows.SetTrailTail(flow, (sol.GetTrailArcs(aux).size() + unassigned_flows.GetTrailTail(flow) -1)); 
                    // S(g) <- null
                    sol.DeleteTrail(aux); 
                }
                // else...
                else{cout<<"6"<<endl; //DEBUG
                    // if |f(h:t)| > 0, then... 
                    if(unassigned_flows.SubtrailSize(flow)){cout<<"7"<<endl; //DEBUG
                        // S <- S u f(h:t) 
                        sol.AddTrail(unassigned_flows.GetTrail(flow)); 
                        // for each a in f(h:t) do... 
                        for(int i= unassigned_flows.GetTrailHead(flow); i < unassigned_flows.GetTrailTail(flow); i++) {cout<<"8"<<endl; //DEBUG
                            // CoveredBy(a) <- c
                            sol.SetCover(cover_index, i, flow); 
                        }
                        // c <- c + 1
                        cover_index++; 
                        // h <- t
                        unassigned_flows.SetTrailHead(flow, unassigned_flows.GetTrailTail(flow)); 
                    }
                    // else... 
                    else{ cout<<"9"<<endl; //DEBUG
                        // h <- h + 1
                        unassigned_flows.SetTrailHead(flow, unassigned_flows.GetTrailHead(flow) + 1);
                        // t <- h
                        unassigned_flows.SetTrailTail(flow, unassigned_flows.GetTrailHead(flow)); 
                    }
                }
            }
        }

        // if |f(h:t)| > 0, then... 
        if(unassigned_flows.SubtrailSize(flow)){cout<<"10"<<endl; //DEBUG
            // S <- S u f(h:t) 
            sol.AddTrail(unassigned_flows.GetTrail(flow));
            // for each a in f(h:t) do... 
            for(int i=0; i < (unassigned_flows.GetTrailTail(flow) - unassigned_flows.GetTrailHead(flow ) ); i++) {cout<<"11"<<endl; //DEBUG
                sol.SetCover(cover_index, i, flow); 
            }
            // c <- c + 1
            cover_index = cover_index + 1; 
        }
    }
    // R <- empty 
    // for each sub-trail s in S do... 
        // for a <- 0, k, 2k, ... do...
        // R<- R u s(a:min(a+k,|s|))
    Set R(sol.Split(capacity)); 
    return R; 
}


bool IsSubtrail(vector <Arc*> a, vector <Arc*> b){
     size_t len = min(a.size(), b.size());

    return equal(a.begin(), a.begin()+len, 
                 b.begin(), b.begin()+len);
}