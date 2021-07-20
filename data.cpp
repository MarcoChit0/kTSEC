#include "data.hpp"

using namespace std; 

Set algorithm_for_NEMO(Set trails, int capacity){
    // S <- empty 
    Set sol({}), unassigned_flows = trails; 
    // c <- 0
    int cover_index = 0; 
    // CoveredBy(a) <- null, for each a in A
        // coveredBy = -1 for all arcs as default 
    // UF <- sort
        // sorted in ascending order by the length of each trail and,
        // in case of ties, in descending order by the sum of the number of trails covering ther arcs of each trail
    unassigned_flows.sort(); 
    // for each f in UF do... 
    for(int flow=0; flow< unassigned_flows.size(); flow++){ 
        // h <- 0
        unassigned_flows.changeTrailHead(flow, 0);
        // t <- 0 
        unassigned_flows.changeTrailTail(flow, 0);
            // head and tail for each tail in unassigned_flows are already equal to EMPTY_TRAIL = 0
        // while t < |f| do... 
        while(unassigned_flows.getTrailTail(flow) < unassigned_flows.getTrailSize(flow)){ 
            // g <- coveredBy(f(t))
            int aux = unassigned_flows.coveredBy(flow, unassigned_flows.getTrailTail(flow));
            // if g = null, then...
            if (aux == NO_COVER){
                // t <- t + 1
                unassigned_flows.changeTrailTail(flow, (unassigned_flows.getTrailTail(flow) + 1));
            }
            // else...
            else{
                // if subtrail(S(g),f), then... 
                if(isSubtrail(sol.getTrailArcs(aux), unassigned_flows.getTrailArcs(flow))){
                    // t <- t + |S(g)|
                    unassigned_flows.changeTrailTail(flow, (sol.getTrailArcs(aux).size() + unassigned_flows.getTrailTail(flow) -1)); 
                    // S(g) <- null
                    sol.deleteTrail(aux); 
                }
                // else...
                else{
                    // if |f(h:t)| > 0, then... 
                    if(unassigned_flows.subtrailSize(flow)){
                        // S <- S u f(h:t) 
                        sol.addTrail(unassigned_flows.getTrail(flow)); 
                        // for each a in f(h:t) do... 
                        for(int i= unassigned_flows.getTrailHead(flow); i < unassigned_flows.getTrailTail(flow); i++) {
                            // CoveredBy(a) <- c
                            sol.changeCover(cover_index, i, flow); 
                        }
                        // c <- c + 1
                        cover_index++; 
                        // h <- t
                        unassigned_flows.changeTrailHead(flow, unassigned_flows.getTrailTail(flow)); 
                    }
                    // else... 
                    else{ 
                        // h <- h + 1
                        unassigned_flows.changeTrailHead(flow, unassigned_flows.getTrailHead(flow) + 1);
                        // t <- h
                        unassigned_flows.changeTrailTail(flow, unassigned_flows.getTrailHead(flow)); 
                    }
                }
            }
        }

        // if |f(h:t)| > 0, then... 
        if(unassigned_flows.subtrailSize(flow)){
            // S <- S u f(h:t) 
            sol.addTrail(unassigned_flows.getTrail(flow));
            // for each a in f(h:t) do... 
            for(int i=0; i < (unassigned_flows.getTrailTail(flow) - unassigned_flows.getTrailHead(flow ) ); i++) {
                sol.changeCover(cover_index, i, flow); 
            }
            // c <- c + 1
            cover_index = cover_index + 1; 
        }
    }
    // R <- empty 
    // for each sub-trail s in S do... 
        // for a <- 0, k, 2k, ... do...
        // R<- R u s(a:min(a+k,|s|))
    Set R(sol.split(capacity)); 
    return R; 
}


bool isSubtrail(vector <Arc*> a, vector <Arc*> b){
     size_t len = min(a.size(), b.size());

    return equal(a.begin(), a.begin()+len, 
                 b.begin(), b.begin()+len);
}